#include <iostream>

using namespace std;

typedef struct
{
    double x, y, z;
} Point;

int main()
{
    Point p = {.x = 1, .y = 2.0, .z = 3.0};
    Point & p_ref = p;
    Point * p_ptr = &p_ref;

    p_ptr->z = 100.0;

    cout << "p.z" << p.z << endl;

    return 0;
}
