#ifndef TE_PRODUCT
#define TE_PRODUCT

#include "te_import_export.h"

#include <string>
#include <set>
#include "instrument.h"

namespace te
{

    class TE_DLL_EXPORT product
    {
        std::string m_symbol;
        double m_tick_size;
        double m_tick_value;
        std::string m_exchange;
        std::string m_currency;
        int m_multiplier;

        typedef std::vector< instrument*> instrument_set;
        instrument_set m_instruments;

    public:

        product( const std::string & m_symbol
        ,double m_tick_size;
        ,double m_tick_value;
        ,const std::string & m_exchange;
        ,const std::string & m_currency;
        ,int m_multiplier);

        virtual ~product();

        const std::string & symbol() const ;
        const std::string & exchange() const ;
        const std::string & currency() const ;
        double tick_size() const ;
        double tick_value() const ;
        int multiplier() const;

        void apply_to_instruments(action<const instrument*>)const;

        void load_market_data();
    private:
        void apply_to_instruments(modify<instrument>);
        void build_roll_dates();
    };
}

#endif // TE_PRODUCT
