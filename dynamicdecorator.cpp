#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

struct Shape{
    virtual string str() const  = 0;
};

struct Circle : Shape{
    float radius;
    Circle(){}
    Circle(float radius): radius{radius} {};
    void resize(float factor){
        radius *= factor;
    }
    string str() const override{
        ostringstream oss;
        oss << "A Circle of radius " << radius << endl;
        return oss.str();
    }
};

struct Square : Shape{
    float side;
    Square(){}
    Square(float side) : side{side}{}
    void resize(float factor){
        side *= factor;
    }
    string str() const override{
        ostringstream oss;
        oss << "A Square with side " << side << endl;
        return oss.str();
    }
};

//now we want to add color to shapes

struct ColoredShape : Shape{
    Shape& shape;
    string color;
    ColoredShape(Shape &shape, const string &color): shape{shape}, color{color}{}
    string str() const override{
        ostringstream oss;
        oss << shape.str() << "has color "<< color << endl;
        return oss.str();
    }

};

struct TranparentShape : Shape{
    Shape& shape;
    uint8_t transparency;
    TranparentShape(Shape &shape, uint8_t transparency):
        shape{shape}, transparency{transparency}{}

    string str() const override{
        ostringstream oss;
        oss << shape.str() << " has "
        << static_cast<float>(transparency)/255.f*100.f
        << "% transparency";
        return oss.str();
    }

};
int main(){
    Square sq{5};

    ColoredShape red_square{sq,"red"};

    cout << sq.str() << red_square.str();
}

