#include "../include/rectangle.h"

#include<iostream>
#include<sstream>

rectangle::rectangle(place& x,place& y,distance& w,distance& h,const std::string& id):_x(x),_y(y),_w(w),_h(h),_id(id){
    std::stringstream sstream;
    sstream<<"("<<_x<<","<<_y<<") , "<<"w="<<_w<<", h="<<_h<<" .";
    _rect_string_coords=sstream.str();
}


const std::string& rectangle::get_id() const{
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




