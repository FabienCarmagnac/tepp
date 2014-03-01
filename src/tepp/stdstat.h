#ifndef TE_STDSTAT_H
#define TE_STDSTAT_H

#include "tepp/import_export.h"

#include <string>
#include <initializer_list>

namespace tepp
{

    class TE_API stdstat
    {
        double m_min = std::numeric_limits<double>::max();
        double m_max = std::numeric_limits<double>::min();
        double m_absmin = std::numeric_limits<double>::max();
        double m_absmax = 0;
        size_t m_n = 0;
        double m_sum = 0;
        double m_sum2 = 0;
        std::string m_name;
    public:
        stdstat(const std::string & name=std::string());

        double minV()const;
        double maxV()const;
        double absmin();
        double absmax();
        double avg()const;
        double stddev()const;
        double variance()const;

        double sum()const;
        double sum2()const;
        size_t n()const;
        const std::string & name()const;

        void add(double d);
        void add(const std::initializer_list<double> &);
    };
}
#endif // TE_STDSTAT_H
