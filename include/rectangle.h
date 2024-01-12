#pragma once

#include<string>

//rectangle coordinates types
using place=int;
using distance=int;

class rectangle{
    public:
        //constructor
        rectangle();

        template <typename Arg>
        rectangle(const place x,const place y,const distance w,const distance h,Arg&& id):_x(x),_y(y),_w(w),_h(h),_id(std::forward<Arg>(id)){
            this->reset_rect_string_coords();
        }
        const std::string& get_id() const;

        place get_x() const;
        place get_y() const;
        distance get_w() const;
        distance get_h() const;
        void set_x(const place);
        void set_y(const place);
        void set_w(const distance);
        void set_h(const distance);

        template <typename Arg>
        void set_id (Arg&& id)   
        {
            _id=std::forward<Arg>(id);
        }
        const std::string& get_string_coords() const;

        void reset_rect_string_coords();

        // 重载 == 运算符
        bool operator==(const rectangle& other_rect) const {
            return _x==other_rect.get_x() && _y == other_rect.get_y() && _w==other_rect.get_w() && _h==other_rect.get_h();
        }
        // 重载 < 运算符
        bool operator<(const rectangle& other_rect) const{
            //if(_x==other_rect.get_x() && _y == other_rect.get_y() && _w==other_rect.get_w() && _h==other_rect.get_h()){
            //    return false;
            //}
            if(*this==other_rect){
                return false;
            }
            else{
                if(_x!=other_rect.get_x()){
                    return _x<other_rect.get_x();
                }
                else if(_y!=other_rect.get_y()){
                    return _y<other_rect.get_y();
                }else if(_h!=other_rect.get_h()){
                    return _h<other_rect.get_h();
                }else{
                    return _w<other_rect.get_w();
                }
            }
        }
    private:
        place _x,_y;
        distance _w,_h;
        std::string _id;
        std::string _rect_string_coords;  //矩阵信息字符串

};