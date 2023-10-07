#include "../include/jsonparser.h"
#include "rapidjson/document.h"
#include<fstream>
#include<iostream>

bool parse_from_path(const char* jsonfile,rapidjson::Document& doc){
    //read json form file
    std::ifstream json_input_file(jsonfile);

    std::string json_input;
    if(json_input_file.is_open()){
        std::string line;
        while (std::getline(json_input_file, line)) {
            json_input+=line;
        }
        if(json_input_file.bad()){
            throw std::runtime_error("read json_input_file error!");
        }
        json_input_file.close();
       }
    else{
        json_input.clear();
        json_input.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"file not exist,please try again!"<<std::endl;
    }

    //use rapidjson deal with json_input





}