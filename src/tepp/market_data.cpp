
#include "market_data.h"
#include "env.h"
#include "string_tools.h"
#include "datetime.h"

#include "../tinyxml/tinyxml.h"

#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <cstdlib>

namespace te
{


market_data::market_data(TiXmlElement * elem, const instrument & instru): m_instrument(instru)
{
    if(elem==NULL) throw std::runtime_error("xml node is null in market_data!");

    const char * s ;

    s = elem->Attribute("filename");
    if(!s) throw std::runtime_error("no attribute filename !");
    m_filename = s;

    s = elem->Attribute("interval");
    if(!s) throw std::runtime_error("no attribute interval!");
    m_interval= atoi(s);

}
market_data::~market_data(){}
const v_bars & market_data::get_bars()const
{
    return m_bars;
}

int market_data::interval()const
{
    return m_interval;
}

void market_data::load_from_file()
{
    std::string filename = resolve_path(m_filename);
    std::ifstream is(filename);
    if( ! is)
        throw std::runtime_error("Cannot load filename " + filename);

    std::string line;
    int i_line=0;
    INFO("market_data", "loading histo file " + filename);
    while(getline(is, line))
    {
        i_line++;
        line=trim(line);
        if(line.size() && line[0] == '#')
            continue;

        if(line.empty())
            continue;

        s_vs tab = split(line, ';', false);

        if(tab->size() < 6)
        {
            ERR("market_data", "loading file " + filename + ", line " + std::to_string(i_line));
            continue;
        }

        tp ddate=strtotp(tab->at(1));
        if( ! is_business_day(ddate))
            continue;

        double open=strtod(tab->at(2).c_str(), NULL);
        double high=strtod(tab->at(3).c_str(), NULL);
        double low=strtod(tab->at(4).c_str(), NULL);
        double close=strtod(tab->at(5).c_str(), NULL);
        double volume=strtod(tab->at(6).c_str(), NULL);

        m_bars.emplace_back(this, ddate, open, high, low, close, volume);
    }

    transformer<bar,tp> t = [](const bar & b){return b.start_date();};
    comparer<bar> by_start_date = bar::compare_by<tp>(t);
    tp tp_min = tp::min();

    for(auto & b : m_bars)
        if(tp_min > b.start_date() ) // need sort
        {
            std::sort(m_bars.begin(), m_bars.end(), by_start_date);
            break;
        }else tp_min = b.start_date();
}
}
