//
//  main.cpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/10/29.
//
#include "coordinate.hpp"
#include <iostream>
#include <random>
using namespace std;

int main() {
    // instantiate a array in stack
    Cooridnate coor[3];
    
    // instantiate a array from the heap
    // p points to the first object in array
    Cooridnate * p = new Cooridnate[3];
    
    // check whether allocation fails
    if(!p) {
        cout << "Allocation Fails.";
    }
    
    coor[0].set_coor_x(10);
    coor[0].set_coor_y(15);
    
    p->set_coor_x(20);
    p[0].set_coor_y(30);
    
    (p + 1)->set_coor_x(40);
    (p + 1)->set_coor_y(50);
    
    p++;
    p++;
    p->set_coor_x(100);
    p->set_coor_y(200);
    
    for (int i = 0; i < 3; i++) {
        cout << "coor_x : " << coor[i].get_coor_x() << endl;
        cout << "coor_y : " << coor[i].get_coor_y() << endl;
    }
    
    for (int i(0); i < 3; i++) {
        cout << "p_x: " << p->get_coor_x() << endl;
        cout << "p_y: " << p->get_coor_y() << endl;
        p--;
    }
    p++;
    
    // delete p only free up the first elemtn of array
    delete []p;
    p = nullptr;

    // int a, b;
    // std::cin >> a >> b;
    // cout << a + b << endl; 
    return 0;
}
