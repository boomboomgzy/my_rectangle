#pragma once

#include<string>
#include "rapidjson/document.h"

namespace gzy_json{
    bool parse_jsonstring_from_file(const std::string&,rapidjson::Document&);
}
