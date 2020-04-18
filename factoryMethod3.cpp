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
public:
    double x, y;
    friend ostream &operator<<(ostream &os, const Point &p){
        os << "x: " <<p.x << " y: " << p.y << endl;
        return os;
    }
    Point(double x, double y):x(x),y(y){};

};


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

int main(){
    auto p = PointFactory::NewCartesian(4,65);
    cout << p << endl;
}
