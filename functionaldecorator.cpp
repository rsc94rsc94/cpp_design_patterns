#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <string>

using namespace std;




struct Logger{
    function<void()> func;
    string name;
    Logger(const function<void()> &func, const string &name):func(func), name(name){}
    void operator()() const{
        cout << "Entering " << name << endl;
        func();
        cout << "Exiting " << name << endl;
    }
};

template <typename Func>
struct Logger2{
    Func func;
    string name;
    Logger2(const Func &func, const string &name):func(func), name(name){}
    void operator()() const{
        cout << "Entering 3" << name << endl;
        func();
        cout << "Exiting " << name << endl;
    }
};

//helper function: type of global factory
template <typename Func>
auto make_logger2(Func func, const string &name){
    return Logger2<Func>{func,name};
}

double add(double a, double b){
    cout << a << "+" <<b << " = " << (a+b) << endl;
    return a+b;
}

template <typename> struct Logger3;
template <typename R, typename... Args>

struct Logger3<R(Args...)>{
    function<R(Args...)> func;
    string name;
    Logger3(const function<R(Args...)> &func, const string &name):func(func), name(name){}
    R operator()(Args ...args) const{
        cout << "Entering " << name << endl;
        R result  = func(args...);
        cout << "Exiting " << name << endl;
        return result;
    }

};

//helper function
template <typename R, typename... Args>

auto make_logger3(R (*func)(Args...), const string &name){
    return Logger3<R(Args...)>(
        function<R(Args...)>(func),
        name
    );
};

int main(){
    //cout << "Hello " << endl;
    Logger2([](){cout << "Hello " << endl;}, " hellowFunction")();
    auto log = make_logger2([](){cout << "Hello " << endl;}, " hellowFunction");
    log();
    auto logger_add = make_logger3(add,"add");
    auto result = logger_add(2,3);
    cout << result << endl;
   //cout <<  Logger3(add, "addition")(4,5) << endl;
}
