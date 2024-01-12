#include<iostream>
#include<string>
#include "rectangle.h"
#include<set>
#include "parser.h"
#include <boost/json.hpp>

int main(int argc,const char* argv[]){

    if(argc!=2){
        std::cout<<"usage: programfile_path jsonfile_path"<<std::endl;
        return -1;
    }
    //load json file
    
    std::string json_str;
    if(!gzy_json::parse_jsonstring_from_file(argv[1],json_str)){
        //解析失败
        return -1;
    }

    std::set<rectangle> vec_rec;
    if(!gzy_json::parse_rectangle_from_jsonstring(json_str,vec_rec)){
        //解析失败
        return -1;
    }
    if(vec_rec.size()<=1){
        std::cout<<"rectangle's num less than 1 !"<<std::endl;
        return -1;
    }

    std::set<rectangle> overlaps_rect;
    
    gzy_json::findoverlaps(vec_rec, overlaps_rect);
    if(overlaps_rect.size()<1)
    {   
        std::cout<<"not overlaps rectangle !"<<std::endl;
        return -1;
    }

    for(const rectangle& rect:overlaps_rect){
        std::cout << "Between rectangle " << rect.get_id() << " at: " << rect.get_string_coords() << std::endl;
    }
  
    
} 

