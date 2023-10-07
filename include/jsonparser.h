#pragma once
#include "rapidjson/document.h"


bool parse_from_path(const char* jsonfile,rapidjson::Document& doc);
