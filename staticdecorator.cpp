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

template <typename T> struct ColoredShape2 : T{
    static_assert(is_base_of<Shape, T>::value,
    "Template argument  must be a Shape");

    string color;
    ColoredShape2(){}
    template <typename...Args>
    ColoredShape2(const string &color, Args ...args)
        :T(std::forward<Args>(args)...), color(color){}

    string str() const override{
        ostringstream oss;
        oss << T::str() << " has the color " << color << endl;
        return oss.str();
    }
};

template <typename T> struct TranparentShape2 : T{
    static_assert(is_base_of<Shape, T>::value,
    "Template argument  must be a Shape");

    uint8_t transparency;
    TranparentShape2(){}
    template <typename...Args>
    TranparentShape2(uint8_t transparency, Args ...args)
        :T(std::forward<Args>(args)...), transparency(transparency){}

    string str() const override{
        ostringstream oss;
        oss << T::str() << " has "
        << static_cast<float>(transparency)/255.f*100.f
        << "% transparency";
        return oss.str();
    }
};


int main(){
    ColoredShape2<Circle> green_circle("green", 5);
    green_circle.resize(2);
    cout << green_circle.str() << endl;
    TranparentShape2<ColoredShape2<Square>> tp_red_sq(5,"red", 10);
    cout << tp_red_sq.str() ;

}


