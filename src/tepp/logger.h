#ifndef TEPP_LOGGER_H
#define TEPP_LOGGER_H

#include <iostream>
#include <string>

namespace tepp
{

#define LOG_BASE0(pref, src, timestr, msg) { std::string ssrc(src); ssrc.resize(15, ' '); \
std::cout << "| " << timestr << " | "  << std::string(pref) << " | " << ssrc << " | " << msg << std::endl;}

#define LOG_BASE(pref, src, msg) LOG_BASE0(pref, src, tepp::now_str()<<' ', msg)


#define TRACE_(src, msg)  LOG_BASE("TRACE", src, msg)
#define TRACE_T(src, time, msg)  LOG_BASE0("TRACE", src, tepp::tptostr(time) <<'*', msg)

#define INFO(msg)   LOG_BASE("INFO ", src, msg)
#define ERR(msg)    LOG_BASE("ERROR", src, msg)
#define WARN(msg)   LOG_BASE("WARNG", src, msg)
#define THROW(msg)  LOG_BASE("THROW", __FILE__ ":" ## __LINE__, msg)

}

#endif // TEPP_LOGGER_H
