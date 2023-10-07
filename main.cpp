#include<iostream>
#include<string>
#include "rapidjson/document.h"

int main(int argc,const char* argv[]){
    //ensure have json input file
    if(argc!=2){
        std::cout<<"usage: programfile_path jsonfile_path"<<std::endl;
        return -1;
    }

    //load json file
    rapidjson::Document document;


}