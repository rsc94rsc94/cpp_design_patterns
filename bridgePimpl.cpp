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


class Person{
public:
    string name;
    class PersonImpl;
    PersonImpl *impl;
    Person(const string &name);
    ~Person();
    void greet();
};

class Person::PersonImpl{
public:
    void greet(Person *p);
};


void Person::PersonImpl::greet(Person *p){
    cout<< "hello my name is " << p->name << endl;
}

Person::Person(const string &name):impl(new PersonImpl()),name(name){}
Person::~Person(){delete impl;}
void Person::greet(){
    impl->greet(this);
}
int main(){
    Person p{"Ritesh"};
    p.greet();
}
