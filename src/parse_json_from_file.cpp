#include <string>
#include "rapidjson/document.h"
#include "../include/parse_jsonstring_from_file.h"
#include <fstream>
#include <sstream>
#include <iostream>
namespace gzy_json
{
    bool parse_jsonstring_from_file(const std::string &file_path, rapidjson::Document &document)
    {
        bool retval = true;
        std::ifstream json_file(file_path, std::ios::in);
        if (json_file.is_open())
        {
            std::stringstream stringbuffer;
            try
            {
                stringbuffer << json_file.rdbuf();
                std::string json_string(stringbuffer.str());
                document.Parse(json_string.c_str());
                if (document.HasParseError()) {
                // 处理解析错误
                    retval=false;
                    std::cerr << "parse error: " << document.GetParseError() << " - offset: " << document.GetErrorOffset() <<  std::endl;
                }
            }
            catch (std::exception const &e)
            {
                std::cerr << e.what() << std::endl;
                retval = false;
            }
            catch (...)
            {
                std::cerr << "error processing input json file with path: " << file_path << std::endl;
                retval = false;
            }

        }
        else
        {
            std::cout << "json_file open failed ! file_path is: " << file_path << std::endl;
            retval = false;
        }

        json_file.close();
        return retval;
    }
}