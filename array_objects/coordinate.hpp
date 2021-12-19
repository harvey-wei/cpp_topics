//
//  coordinate.hpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/10/29.
//

#ifndef coordinate_hpp
#define coordinate_hpp
class Cooridnate {
public:
    Cooridnate(int _x=0, int _y=0);
    ~Cooridnate();
    void set_coor_x(int _x);
    void set_coor_y(int _y);
    int get_coor_x();
    int get_coor_y();
    
private:
    int m_int_x;
    int m_int_y;
};

#endif /* coordinate_hpp */
