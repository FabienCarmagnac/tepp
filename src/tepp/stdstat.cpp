
#include "stdstat.h"

#include <limits>
#include <cmath>

namespace tepp
{

double stdstat::minV()const
{
    return m_min;
}
double stdstat::maxV()const
{
    return m_max;
}
double stdstat::absmin()
{
    return m_absmin;
}
double stdstat::absmax()
{
    return m_absmax;
}
double stdstat::avg()const
{
    return (m_n==0 ? std::numeric_limits<double>::quiet_NaN() : m_sum/m_n);
}
double stdstat::stddev()const
{
    return std::sqrt(variance());
}
double stdstat::variance()const
{
    return (m_n==0 ? std::numeric_limits<double>::quiet_NaN() : m_sum2 / m_n - (m_sum*m_sum)/(m_n*m_n));
}

double stdstat::sum()const
{
    return m_sum;
}
double stdstat::sum2()const
{
    return m_sum2;
}
size_t stdstat::n()const
{
    return m_n;
}
const std::string & stdstat::name()const
{
    return m_name;
}

stdstat::stdstat(const std::string & name)
{
    m_name = name;
    
}

void stdstat::add(double d)
{
    if (d < m_min) m_min = d;
    if (d > m_max) m_max = d;
    double abs = fabs(d);
    if (m_absmin > abs) m_absmin = abs;
    if (m_absmax < abs) m_absmax = abs;

    m_sum += d;
    m_sum2 += d * d;

    m_n++;
}
void stdstat::add(const std::initializer_list<double> & l)
{
    for(double d : l)
    {
        add(d);
    }

}
}
