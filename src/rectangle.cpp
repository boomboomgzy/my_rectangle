#include "../include/rectangle.h"

#include<iostream>
#include<sstream>
#include<set>

void rectangle::reset_rect_string_coords(){
    std::stringstream sstream;
    sstream<<"("<<_x<<","<<_y<<") , "<<"w="<<_w<<", h="<<_h<<" .";
    _rect_string_coords=sstream.str();
}

rectangle::rectangle()=default;




const std::set<int>& rectangle::get_id() const{
    return _id;
}

const std::string& rectangle::get_string_coords() const{
    return _rect_string_coords;
}
place rectangle::get_x() const{
    return _x;
};
place rectangle::get_y() const{
    return _y;
};
distance rectangle::get_w() const{
    return _w;
};
distance rectangle::get_h() const{
    return _h;
};

void rectangle::set_x(const place x){
    _x=x;
}
void rectangle::set_y(const place y){
    _y=y;
}
void rectangle::set_w(const distance w){
    _w=w;
}
void rectangle::set_h(const distance h){
    _h=h;
}







