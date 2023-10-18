#include<iostream>
#include<string>
#include "rapidjson/document.h"
#include "include/rectangle.h"
#include<vector>
#include "include/parse_jsonstring_from_file.h"

int main(int argc,const char* argv[]){
    //ensure have json input file
    if(argc!=2){
        std::cout<<"usage: programfile_path jsonfile_path"<<std::endl;
        return -1;
    }

    //load json file
    rapidjson::Document document;
    gzy_json::parse_jsonstring_from_file(argv[1],document);
    
        //json文件读取成功，从中获取rectangle对象
    if(document.HasMember("rects") && document["rects"].IsArray()){
       const rapidjson::Value& rects = document["rects"];
       for(rapidjson::SizeType i=0;i<rects.Size();i++){
         std::cout<<rects[i]["x"].GetInt()<<std::endl;
       }
    }
}