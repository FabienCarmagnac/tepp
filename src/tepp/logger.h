#ifndef TEPP_LOGGER_H
#define TEPP_LOGGER_H

#include <iostream>

namespace tepp
{

#define LOG_BASE(pref, src, msg) { std::string ssrc(src); ssrc.resize(15); std::string s = "| " + te::now_str() + " | "  + std::string(pref) + " | " + ssrc + " | " + msg + "\n"; std::cout << s;}

#define INFO(msg)   LOG_BASE("INFO ", src, msg)
#define ERR(msg)    LOG_BASE("ERROR", src, msg)
#define WARN(msg)   LOG_BASE("WARNG", src, msg)
#define THROW(msg)  LOG_BASE("THROW", __FILE__ ":" ## __LINE__, msg)

}

#endif // TEPP_LOGGER_H
