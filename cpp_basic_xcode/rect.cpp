//
//  rect.cpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/11/1.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct MyPoint {
    MyPoint(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
    double x, y;
};

int main() {
    vector<MyPoint> point_set_a;
    vector<MyPoint> point_set_b;
    
    for (int i = 1; i <= 4; i++)
    {
        double x, y;
        cin >> x >>y;
        point_set_a.emplace_back(MyPoint(x, y));
    }
    
    for (int i = 1; i <= 4; i++)
    {
        double x, y;
        cin >> x >>y;
        point_set_b.emplace_back(MyPoint(x, y));
    }
    
//    cout << point_set_a[0].x << endl;
    double a_tl_x, a_tl_y, a_br_x, a_br_y;
    a_tl_x = min(min(min(point_set_a[0].x, point_set_a[1].x), point_set_a[2].x),point_set_a[3].x);
    a_tl_y = max(max(max(point_set_a[0].y, point_set_a[1].y), point_set_a[2].y),point_set_a[3].y);
    a_br_x = max(max(max(point_set_a[0].x, point_set_a[1].x), point_set_a[2].x),point_set_a[3].x);
    a_br_y = min(min(min(point_set_a[0].y, point_set_a[1].y), point_set_a[2].y),point_set_a[3].y);
    
    double b_tl_x, b_tl_y, b_br_x, b_br_y;
    b_tl_x = min(min(min(point_set_a[4].x, point_set_a[5].x), point_set_a[6].x),point_set_a[7].x);
    b_tl_y = max(max(max(point_set_a[4].y, point_set_a[5].y), point_set_a[6].y),point_set_a[7].y);
    b_br_x = max(max(max(point_set_a[4].x, point_set_a[5].x), point_set_a[6].x),point_set_a[7].x);
    b_br_y = min(min(min(point_set_a[4].y, point_set_a[5].y), point_set_a[6].y),point_set_a[7].y);

    double tl_x, tl_y, bl_x, bl_y;
    tl_x = max(a_tl_x, b_tl_x);
    tl_y = min(a_tl_y, b_tl_y);
    bl_x = min(a_br_x, b_br_x);
    bl_y = max(a_br_y, b_br_y);
    
    double width = bl_x - tl_x;
    double height = tl_y -  bl_y;
    
    if (width > 0 and height >0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
