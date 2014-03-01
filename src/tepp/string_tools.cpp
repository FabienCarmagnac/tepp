

#include "string_tools.h"


namespace tepp
{

    s_vT< std::string > split(const std::string & s, char sep, bool remove_empty)
    {
        s_vT< std::string > ret = s_vT< std::string > (new std::vector< std::string > () );
        size_t begin=0, end=0;

        while(end<s.size())
        {
            if(s[end]==sep)
            {
                std::string t = s.substr(begin, end-begin);
                t = trim(t);
                if( ! remove_empty || ! t.empty())
                    ret->push_back(t);
                begin=end+1;
            }
            end++;
        }

        std::string t = s.substr(begin, end-begin);
        t = trim(t);
        if( ! remove_empty || ! t.empty())
            ret->push_back(t);


        return ret;
    }

    std::string trim(const std::string & s)
    {
        static std::string separators(" \n\t");
        size_t end, begin;
        for(begin=0;begin < s.size();++begin)
            if(separators.find(s[begin])==std::string::npos) // trouvé, on arrête
                break;

        for(end=s.size();end>0;--end)
            if(separators.find(s[end-1])==std::string::npos) // trouvé, on arrête
                break;

        if(begin!=0 || end!=s.size())
            return s.substr(begin, end-begin);
        else return s;
    }


}
