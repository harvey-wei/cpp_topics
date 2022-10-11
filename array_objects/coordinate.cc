//
//  coordinate.cpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/10/29.
//

#include "coordinate.hpp"
#include <iostream>
using namespace std;

Cooridnate::Cooridnate(int _x, int _y){
    m_int_x = _x;
    m_int_y = _y;

    cout << "Cooridnate::Cooridnate(int _x, int _y)" << endl;
}

Cooridnate::~Cooridnate() {
    cout << "~Coordiante()" << endl;
}

void Cooridnate::set_coor_x(int _x) {
    m_int_x = _x;
}

void Cooridnate::set_coor_y(int _y) {
    m_int_y = _y;
}

int Cooridnate::get_coor_x() {
    return m_int_x;
}

int Cooridnate::get_coor_y() {
    return m_int_y;
}

