
#include "product.h"

#include "datetime.h"

#include <stdexcept>
#include <map>

namespace te
{
product::product(XmlElement * xml)
{
    std::string s;

    s = xml->Attribute("symbol");
    if(s.empty()) throw std::runtime_error("Error: no symbol element in xml tag");
    m_symbol = s;

    INFO("product " + s, "reading product "+ s);

    s = xml->Attribute("currency");
    if(!s.empty()) throw std::runtime_error("Error: no currency element in xml tag");
    m_currency = s;

    s = xml->Attribute("exchange");
    if(!s.empty()) throw std::runtime_error("Error: no exchange element in xml tag");
    m_exchange = s;

    s = xml->Attribute("tick_size");
    if(!s.empty()) throw std::runtime_error("Error: no tick_size element in xml tag");
    m_tick_size = std::stod(s);

    s = xml->Attribute("tick_value");
    if(!s.empty()) throw std::runtime_error("Error: no tick_value element in xml tag");
    m_tick_value = std::stod(s);

    s = xml->Attribute("multiplier");
    if(!s.empty()) throw std::runtime_error("Error: no multiplier element in xml tag");
    m_multiplier = std::stoi(s);

    TiXmlElement* instruXml = xml->FirstChildElement( "instrument" );
    if(!instruXml) return;
    do
    {
        m_instruments.push_back(new instrument(instruXml, *this));
    }
    while( (instruXml = instruXml->NextSiblingElement("instrument"))!=NULL);

}
product::~product() {}

const std::string & product::symbol() const
{
    return m_symbol;
}
const std::string & product::exchange() const
{
    return m_exchange;
}
const std::string & product::currency() const
{
    return m_currency;
}
double product::tick_size() const
{
    return m_tick_size;
}
double product::tick_value() const
{
    return m_tick_value;
}
int product::multiplier() const
{
    return m_multiplier;
}

void product::apply_to_instruments(action<const instrument*> ac)const
{
     for(const instrument* i : m_instruments)
        ac(i);
}
void product::apply_to_instruments(action<instrument*> ac)
{
     for(instrument* i : m_instruments)
        ac(i);
}

void product::load_market_data()
{/*
    INFO("product " + m_symbol, "loading market data for " + symbol());
    workers myworkers("product::load_market_data");
    apply_to_instruments([](instrument * i) { i->load_market_data();});
    INFO("product " + m_symbol, "building rolls ...");
    build_roll_dates();
    INFO("product " + m_symbol,  "done.");
    */
}

void product::build_roll_dates()
{

    /** pour chaque instrument, comlpacter par jour */

    class instru_int
    {
        public: instrument* instru; int vol;
        instru_int(instrument * i, int v):instru(i),vol(v){}
    };
    typedef std::multimap<tp,instru_int> map_tp_int;

    map_tp_int m;

    for(instrument * i : m_instruments)
    {
        const v_bars & vb = i->get_market_data().get_bars();

        int * accum(NULL);
        tp oldday;
        for(const bar & b : vb)
        {
            tp day = to_day(b.start_date());

            if(day != oldday) // nouvelle journée
            {
                map_tp_int::iterator it = m.insert(std::make_pair(day, instru_int(i,0)));
                accum = & (it->second.vol);
            }else
                (*accum) += b.volume();

            oldday=day;
        }
    }

    instru_int * max_vol_for_d(NULL);
    instrument * oldinstru(NULL),*previous_roll(NULL);

    map_tp_int::iterator begin(m.begin());
    tp d;

    std::function<bool()> crit_has_data = [&begin, &m, &d](){ return begin != m.end() && begin->first == d;};

    /* for each day, extract high volume for day and check previous isntru */
    for( ; begin != m.end() ; )
    {
        d = begin->first;
        std::cout << tptostr(d) << " : " << begin->second.instru->get_full_symbol() << " vol=" << begin->second.vol << ", ";

        max_vol_for_d = & begin->second;
        begin++;

        while(crit_has_data()) // find max of volume for d
        {
            std::cout << begin->second.instru->get_full_symbol() << " vol=" << begin->second.vol << ", ";
            if(max_vol_for_d->vol < begin->second.vol)
                max_vol_for_d= & (begin->second);

            begin++;
        }

        if(oldinstru==NULL)
            oldinstru=max_vol_for_d->instru;

        // new instrument, may be a roll !
        if(max_vol_for_d->instru != oldinstru)
        {
            if(max_vol_for_d->instru == previous_roll ) // only one elem, anomaly, skip
            {
                WARN("product " + m_symbol, "day " + tptostr(d) + " re-roll ! skipping day ...");
                continue;
            }

            INFO("product " + m_symbol, oldinstru->get_full_symbol() + " : " + max_vol_for_d->instru->get_full_symbol() + " : " + tptostr(d));
            oldinstru->set_roll_date(d);
            oldinstru->set_next_roll(max_vol_for_d->instru);
            oldinstru->set_previous_roll(previous_roll);
            if(previous_roll)
                previous_roll->set_next_roll(oldinstru);

            previous_roll=oldinstru;
            oldinstru=max_vol_for_d->instru;
        }

    }


}

}//ns


