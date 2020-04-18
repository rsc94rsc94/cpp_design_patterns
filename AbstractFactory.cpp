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


class HotDrink
{
public:
    HotDrink(){}
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

class Tea : public HotDrink
{
public:
    void prepare(int volume){
        cout << "take water, add sugar and tea, add ginder boil" << endl;
    }
};

class Coffee : public HotDrink
{
public:
    void prepare(int volume){
        cout << " grind some beans"  << endl
           << "boil water "  << volume <<
           "ml " << "enjoy " << endl;
    }
};

class HotDrinkFactory{ // Abstract Factory
public:
    virtual unique_ptr<HotDrink>  make() const  = 0;
};

class TeaFactory : public HotDrinkFactory{ //concrete factory
public:
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

class CoffeeFactory : public HotDrinkFactory{
public:
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};

//If we dont use abstract factory;
unique_ptr<HotDrink> make_drink(string type){
    unique_ptr<HotDrink> drink;
    if(type == "tee"){
        drink = make_unique<Tea>();
        drink->prepare(100);
    }
    else{
        drink = make_unique<Coffee>();
        drink->prepare(100);
    }
    return drink;
}

//If we have abstract factory we can make a concrete factory;
class DrinkFactory
{
    map<string ,unique_ptr<HotDrinkFactory>> hot_factory;
public:

    DrinkFactory(){
        hot_factory["coffee"] = make_unique<CoffeeFactory>();
        hot_factory["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name){
        auto drink = hot_factory[name]->make();
        drink->prepare(100);
        return drink;
    }

};

int main(){
   auto d = make_drink("tee");
   DrinkFactory df;
   auto c = df.make_drink("coffee");

}
