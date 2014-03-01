#ifndef TE_CONTRACT
#define TE_CONTRACT

namespace te
{
    class contract
    {
    private:

        std::string m_symbol; // ex: CL for crude oil
        std::string m_currency; //ex: EUR
        std::string m_full_symbol; // ex: CLH1
        std::string m_exchange; // mic ?
    public:
        contract(const std::string & symbol, const std::string & currency, const std::string & full_symbol, const std::string & exchange);
        virtual ~contract();




    };

}


#endif // TE_CONTRACT
