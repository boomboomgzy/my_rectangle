#pragma once

#include<string>

//rectangle coordinates types
using place=int;
using distance=unsigned int;

class rectangle{
    public:
        //constructor
        rectangle(place& x,place& y,distance& w,distance& h,const std::string& id);
        const std::string& get_id() const;

        place get_x() const;
        place get_y() const;
        distance get_w() const;
        distance get_h() const;
        const std::string& get_string_coords() const;
        

    private:
        place _x,_y;
        distance _w,_h;
        const std::string _id;
        std::string _rect_string_coords;  //矩阵信息字符串

};