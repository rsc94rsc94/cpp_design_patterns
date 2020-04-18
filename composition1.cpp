
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>

using namespace std;

struct GraphicObject{
    virtual void draw() = 0;
};

struct Circle : public GraphicObject{
    void draw() override {
        cout << "Circle" << endl;
    }
};

struct Group : public GraphicObject{
    string name;
    vector<GraphicObject*> objects;
    Group(const string& name): name(name){}

    void draw() override{
        cout << "Group: " << name << endl;
        for(auto&&o:objects)
            o->draw();
    }
};

int main(){
    Group root{"root"};
    Circle c1,c2;
    root.objects.push_back(&c1);
    Group sub{"sub"};
    sub.objects.push_back(&c2);
    root.objects.push_back(&sub);
    root.draw();

}
