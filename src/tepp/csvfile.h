#ifndef TEPP_CSVFILE_H_
#define TEPP_CSVFILE_H_

#include <string>
#include <fstream>
#include <functional>

#include "tepp/string_tools.h"
#include "tepp/gentypes.h"

namespace tepp
{
	/* Reads a csv file, split each line with the sep char and inserts
	 * at the end of the container the result of the fonction f if the boolean 2nd param is true.
	 * Function is type of std::function< T(const vec_str&, bool& ) >
	 * **/
template < class Function, class Container > bool read_csv(const str & filename, char sep, Function f, Container & container)
{
    std::ifstream ifs(filename.c_str());
	vec_str tab;
    if( ! ifs)
		return false;
		
	std::string line;
	while(getline(ifs, line))
	{
		line=trim(line);
		if(line.size() && line[0] == '#')
			continue;
		split(line, sep, tab, false);

		bool valid(false);
		auto t = f(tab, valid);
		if(valid)
			container.insert(container.end(), t);
		tab.clear();
	}
	return true;
}

}

#endif // TEPP_CSVFILE_H_
