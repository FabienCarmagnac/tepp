#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <vector>

#include "bar.h"

class XmlElement;

namespace te
{

    class market_data
    {
        int m_interval;
        const instrument & m_instrument;
        std::string m_filename;
        v_bars m_bars;
    public:
        market_data(XmlElement*, const instrument&);
        virtual ~market_data();
        int interval()const;
        void load_from_file();
        const v_bars & get_bars()const;


    };
}


#endif // MARKET_DATA_H


