#include "instrument.h"

#include <stdexcept>
#include <iostream>
#include <string>

#include "datetime.h"
#include "../tinyxml/tinyxml.h"

namespace te
{

instrument::instrument(TiXmlElement * xml, const product& p): m_product(p),
m_market_data(xml->FirstChildElement("market_data"), *this)
{
    if(xml==NULL) throw std::runtime_error("xml node is null in instrument !");
    const char * s;

    s=xml->Attribute("full_symbol");
    if(!s) throw std::runtime_error("no full_symbol attribute !");
    m_full_symbol=s;

    s=xml->Attribute("roll_date");
    if(s)
    {
        m_roll_date = strtotp(s);
    }

    s=xml->Attribute("expiry_date");
    if(!s) throw std::runtime_error("no expiry_date attribute for instru " + m_full_symbol);
    m_expi_date = strtotp(s);

}
const instrument * instrument::get_next_roll()const{ return m_next_roll;}
const instrument * instrument::get_previous_roll()const{ return m_previous_roll;}
const instrument * instrument::get_next_expi()const{return m_next_expi;}
const instrument * instrument::get_previous_expi()const{return m_previous_expi;}

void instrument::set_next_roll(const instrument *i){ m_next_roll=i;}
void instrument::set_previous_roll(const instrument *i){ m_previous_roll=i;}
void instrument::set_next_expi(const instrument *i){ m_next_expi=i;}
void instrument::set_previous_expi(const instrument *i){ m_previous_expi=i;}

const product & instrument::get_product()const{    return m_product;}
const std::string & instrument::get_full_symbol()const{    return m_full_symbol;}

const tp & instrument::get_roll_date() const{   return m_roll_date; }
void instrument::set_roll_date(tp d) {     m_roll_date=d; }



comparer<instrument*> instrument::compare_by_expi_date()
{
    return [](const instrument* i1,const instrument* i2){ return i1->m_expi_date < i2->m_expi_date; };
}
comparer<instrument*> instrument::compare_by_roll_date()
{
    return [](const instrument* i1,const instrument* i2){ return i1->m_roll_date < i2->m_roll_date ; };
}

void instrument::load_market_data()
{
    m_market_data.load_from_file();
}
const market_data & instrument::get_market_data()const
{
    return m_market_data;
}
}

