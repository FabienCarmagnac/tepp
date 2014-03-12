

#include "string_tools.h"


namespace tepp
{

    void split(const str & s, char sep, vec_str & ret, bool remove_empty)
    {
        size_t begin=0, end=0;
        while(end<s.size())
        {
            if(s[end]==sep)
            {
                str t = s.substr(begin, end-begin);
                t = trim(t);
                if( ! remove_empty || ! t.empty())
                    ret.push_back(t);
                begin=end+1;
            }
            end++;
        }

        str t = s.substr(begin, end-begin);
        t = trim(t);
        if( ! remove_empty || ! t.empty())
            ret.push_back(t);

    }

    str trim(const str & s)
    {
        static str separators(" \n\t");
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
