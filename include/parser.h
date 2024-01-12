#pragma once

#include<string>
#include<set>
#include "rectangle.h"

namespace gzy_json{
    bool parse_jsonstring_from_file(const std::string&,std::string&);
    bool parse_rectangle_from_jsonstring(std::string&,std::set<rectangle>&);
    void findoverlaps(const std::set<rectangle>&, std::set<rectangle>&);
}
