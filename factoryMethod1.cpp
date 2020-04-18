
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>

using namespace std;

//without factory using type to construct different type of
//object and we cant identify with argument type of we can not easily tell
//that what means what like what does a means and what does b means
//so we use factory patterns for that.
enum class PointType{
    cartesian,
    polar
}

class Point
{
public:
    double x,y;
    //Point(double x, double y):x(y),y(y){}
    Point(double a, double b, PointType type = PointType::cartesian)
    {
        if(type == PointType::cartesian){
            x = a;
            y = b;
        }
        else{
            x = a*cos(b);
            y = a*sin(b);
        }
    }
};
