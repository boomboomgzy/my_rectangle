#include "../include/rectangle.h"

#include<iostream>
#include<sstream>

rectangle::rectangle(place& x,place& y,distance& w,distance& h,const std::string& id):_x(x),_y(y),_w(w),_h(h),_id(id){}

//使用sstream来实现
std::string& rectangle::to_string() const{
    std::stringstream sstream;
    sstream<<"("<<_x<<","<<_y<<") , "<<"w="<<_w<<", h="<<_h<<" .";
    std::string s=sstream.str();
    return s;
}

