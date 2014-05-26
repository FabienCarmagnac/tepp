#ifndef TEPP_INSTRUMENT_H
#define TEPP_INSTRUMENT_H

namespace tepp
{

    class instrument
    {
    };
/*
        std::string m_full_symbol, m_filename;
        const product & m_product;
        tp m_roll_date;
        tp m_expi_date;

        market_data m_market_data;

        const instrument *m_next_roll, *m_previous_roll, *m_next_expi, *m_previous_expi;

    public:
        instrument(TiXmlElement * xml, const product& );

        const tp & get_roll_date() const;
        void set_roll_date(tp);
        const product & get_product()const;

        void set_next_roll(const instrument *);
        void set_previous_roll(const instrument *);
        void set_next_expi(const instrument *);
        void set_previous_expi(const instrument *);

        const instrument * get_next_roll()const;
        const instrument * get_previous_roll()const;
        const instrument * get_next_expi()const;
        const instrument * get_previous_expi()const;

        bool is_last()const;
        const std::string & get_full_symbol()const;

        const market_data & get_market_data()const;

        void load_market_data();

        static comparer<instrument*> compare_by_expi_date();
        static comparer<instrument*> compare_by_roll_date();

    };*/


}

#endif // TEPP_INSTRUMENT_H
