#pragma once

#include<string>

//rectangle coordinates types
using place=int;
using distance=unsigned int;

class rectangle{
    public:
        //constructor
        rectangle(place& x,place& y,distance& w,distance& h,const std::string& id);
        std::string& get_id() const;
        std::string& to_string() const;

        place& get_x() const;
        place& get_y() const;
        distance& get_w() const;
        distance& get_h() const;

    private:
        place _x,_y;
        distance _w,_h;
        const std::string _id;

};