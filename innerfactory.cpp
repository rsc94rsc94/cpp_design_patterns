#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>

using namespace std;


class Point
{
private:
    double x, y;
    friend ostream &operator<<(ostream &os, const Point &p){
        os << "x: " <<p.x << " y: " << p.y << endl;
        return os;
    }
    Point(double x, double y):x(x),y(y){};
    class PointFactory
    {
    public:
        static Point NewCartesian(double x, double y){
            return {x,y};
        }
        static Point NewPolar(double r, double theta){
            return {r*cos(theta), r*sin(theta)};
        }
    };
//Alternative make point factory private. provide a static variable
// or static method to get factory object
public:
    static PointFactory Factory;

};


int main(){
    //auto p = Point::PointFactory::NewPolar(5,45);
//when pointfactory is not public:
    auto p = Point::Factory.NewPolar(5,45);
    cout << p << endl;
}
