#ifndef TE_LOGGER_H
#define TE_LOGGER_H

#include <iostream>
#include <log4cxx/logger.h>

namespace tepp
{

#define LOG_BASE(pref, src, msg) { std::string ssrc(src); ssrc.resize(15); std::string s = "| " + te::now_str() + " | "  + std::string(pref) + " | " + ssrc + " | " + msg + "\n"; std::cout << s;}

#define INFO(msg)   LOG_BASE("INFO ", src, msg)
#define ERR(msg)    LOG_BASE("ERROR", src, msg)
#define WARN(msg)   LOG_BASE("WARNG", src, msg)
#define THROW(msg)  LOG_BASE("THROW", __FILE__ ":" ## __LINE__, msg)

}

#endif // TE_LOGGER_H
