#include "../include/parser.h"
#include "rectangle.h"
#include <string>
#include <iostream>
#include <fstream>
#include <boost/json.hpp>



namespace gzy_json
{
    bool parse_jsonstring_from_file(const std::string &json_file_path, std::string &json_str)
    {
        std::ifstream json_file(json_file_path); 
        std::string line;
        json_str="";
        if (json_file.is_open())
        { 
            while (std::getline(json_file, line))
            {                              
                json_str+=line;
            }
            json_file.close(); 
            return true;
        }
        else
        {
            std::cerr << "Unable to open file";
            return false; 
        }
    }
    
    bool parse_rectangle_from_jsonstring(std::string& json_str,std::set<rectangle>& vec_rec){
        boost::json::error_code ec;
        // error: cannot bind non-const lvalue reference of type ‘boost::json::value&’ to an rvalue of type ‘boost::json::value’
        boost::json::value json_value=boost::json::parse(json_str,ec);
        if( ec ){
            std::cerr << "json string parsing failed : " << ec.message() << "\n";
            return false;
        }
        boost::json::object* rects_obj = json_value.if_object();
        if( rects_obj==nullptr ) return false;
        if(!rects_obj->if_contains("rects") || !rects_obj->at("rects").is_array()){
            std::cerr<<"parse rects from json string failed !"<<std::endl;
            return false;
        }
        const boost::json::array& rects_arr=rects_obj->at("rects").get_array();
        int count=0;
        for(const boost::json::value& rect:rects_arr){
            const boost::json::object* rect_obj=rect.if_object();
            if(rect_obj == nullptr){
                std::cerr<<"parse rect error in no. "<<count+1<<std::endl;
                return false;
            }
            rectangle* new_rectangle=new rectangle();
            if(rect_obj->if_contains("x") && rect_obj->at("x").is_int64()){
                new_rectangle->set_x(rect_obj->at("x").get_int64());
            }else{
                std::cerr<<"parse rect error in no. "<<count+1<<" when dealing x"<<std::endl;
                return false;
            }
            if(rect_obj->if_contains("y") && rect_obj->at("y").is_int64()){
                new_rectangle->set_y(rect_obj->at("y").get_int64());
            }else{
                std::cerr<<"parse rect error in no. "<<count+1<<" when dealing y"<<std::endl;
                return false;
            }
            if(rect_obj->if_contains("h") && rect_obj->at("h").is_int64()){
                new_rectangle->set_h(rect_obj->at("h").get_int64());
            }else{
                std::cerr<<"parse rect error in no. "<<count+1<<" when dealing h"<<std::endl;
                return false;
            }
            if(rect_obj->if_contains("w") && rect_obj->at("w").is_int64()){
                new_rectangle->set_w(rect_obj->at("w").get_int64());
            }else{
                std::cerr<<"parse rect error in no. "<<count+1<<" when dealing w"<<std::endl;
                return false;
            }

            count+=1;
            new_rectangle->set_id(std::to_string(count));
            new_rectangle->reset_rect_string_coords();
            vec_rec.insert(*new_rectangle);
           
            }

             return true;
        }

            

        
    
    
    const rectangle* find_overlaps_between_2_rect(const rectangle& rect_a,const rectangle& rect_b){
        
        place rect_a_lu_x=rect_a.get_x();
        place rect_b_lu_x=rect_b.get_x();
        place rect_a_lu_y=rect_a.get_y();
        place rect_b_lu_y=rect_b.get_y();
        
        place rect_a_rd_x=rect_a.get_x()+rect_a.get_w();
        place rect_b_rd_x=rect_b.get_x()+rect_b.get_w();
        place rect_a_rd_y=rect_a.get_y()+rect_a.get_h();
        place rect_b_rd_y=rect_b.get_y()+rect_b.get_h();

        place overlap_lu_x=std::max(rect_a_lu_x,rect_b_lu_x);
        place overlap_lu_y=std::max(rect_a_lu_y,rect_b_lu_y);
        place overlap_rd_x=std::min(rect_a_rd_x,rect_b_rd_x);
        place overlap_rd_y=std::min(rect_a_rd_y,rect_b_rd_y);

        if(overlap_lu_x<overlap_rd_x && overlap_lu_y<overlap_rd_y){
            return new rectangle(overlap_lu_x,overlap_lu_y,overlap_rd_x-overlap_lu_x,overlap_rd_y-overlap_lu_y,rect_a.get_id()+" and "+rect_b.get_id());
        }
        else{
            return nullptr;
        }
    }
//输出结果不好看
    void findoverlaps(const std::set<rectangle>& input_rect, std::set<rectangle>& overlaps_rect){
        if(input_rect.size()<=1){
            return;    
        }
        std::set<rectangle> new_input_rect;
        for (std::set<rectangle>::iterator it_main_rect = input_rect.begin(); it_main_rect != input_rect.end(); ++it_main_rect) {
            for(std::set<rectangle>::iterator it_rect=std::next(it_main_rect);it_rect!=input_rect.end();++it_rect){
                const rectangle* overlaps_rect_ptr=find_overlaps_between_2_rect(*it_main_rect,*it_rect);
                if(overlaps_rect_ptr){
                    overlaps_rect.insert(*overlaps_rect_ptr);
                    new_input_rect.insert(*overlaps_rect_ptr);
                }
            }
        }
        findoverlaps(new_input_rect,overlaps_rect);
    }
}
