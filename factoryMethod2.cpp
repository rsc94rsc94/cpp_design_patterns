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

    static Point NewCartesian(double x, double y){
        return {x,y};
    }
    static Point NewPolar(double r, double theta){
        return {r*cos(theta), r*sin(theta)};
    }
    friend ostream &operator<<(ostream &os, const Point &p){
        os << "x: " <<p.x << " y: " << p.y << endl;
        return os;
    }
private:
    Point(double x, double y):x(x),y(y){};
protected:
private:
};

int main(){
    auto p = Point::NewPolar(5,M_PI_4);
    cout << p << endl;
}
