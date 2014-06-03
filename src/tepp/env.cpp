
#ifdef _WIN32
#include <windows.h>
#elif MACOS
#include <sys/param.h>
#include <sys/sysctl.h>
#else
#include <unistd.h>
#endif

#include "env.h"

#include <stdexcept>

#pragma warning( disable : 4996 ) 

namespace tepp
{
	const std::string & empty_string()
	{
		static std::string r;		
		return r;
	}
    const std::string & root()
    {

        static std::string s ;
        if(s.empty())
        {
            const char * v = getenv(TEPP_ENV_VAR);
            if(!v)
                throw std::runtime_error("Please set system variable " + std::string(TEPP_ENV_VAR) + " or change TEPP_ENV_VAR itself and recompile tepp.");
            s=v;
        }
        return s;
    }

    std::string resolve_path(const std::string & s)
    {
        std::string var = std::string("$") + TEPP_ENV_VAR;
        size_t pos = s.find(var);
        if(pos==std::string::npos) // not found
            return s;

        return s.substr(0, pos) + root() + s.substr(pos+var.size());
    }

size_t get_nb_cores()
{
#ifdef WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
#elif MACOS
    int nm[2];
    size_t len = 4;
    uint32_t count;

    nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);

    if(count < 1) {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if(count < 1) { count = 1; }
    }
    return count;
#else
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}
}
