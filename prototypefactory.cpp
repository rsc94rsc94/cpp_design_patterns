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


struct Address{
    string street, city;
    int suite;
    Address(const string &street, const string &city, int suite):
    street{street}, city{city},suite{suite}{}

    Address(const Address &add):street{add.street}, city{add.city}, suite{add.suite}{}
    friend ostream& operator<<(ostream &os, const Address &address){
        os << "street: " << address.street << " city: " << address.city
        << " suite: " << address.suite << endl;
        return os;
    }
};

struct Contact{
    string name;
    Address * address;
    Contact(const string &name, Address * address):
    name(name), address(address){}

    //Contact(const Contact &other):name(other.name),
    //address{new Address{other.address->street, other.address->city, other.address->suite}}{}
    Contact(const Contact &other):name(other.name),
    address{new Address{*other.address}}{}

    friend ostream& operator<<(ostream& os, const Contact &c){
        os << "Name: " << c.name << " Address: " << *c.address ;
        return os;
    }
    ~Contact(){delete address;}
};

//make a global variable:
Contact mainE{"" , new Address("123 east dr", "London", 0)};
// or make a factory

struct EmployeeFactory{
    static unique_ptr<Contact> NewMainOfficeEmployee
        (const string &name, const int suite){
            static Contact p{"",new Address{"123 east dr", "London", 0}};
            return NewEmployee(name,suite,p);
        }
private:
    static unique_ptr<Contact> NewEmployee(const string& name, int suite,
        const Contact &prototype){
            auto result = make_unique<Contact>(prototype);
            result->name = name;
            result->address->suite = suite;
            return result;
        }
};

int main(){
    Contact john{"john Doe" , new Address("123 east dr", "London", 123)};

    Contact jane = john;//shallow copy;
    //john is a prototype here and we are using john to initialize
    //other instances and changing them accordingly;
    jane.name = "Jane Smith";
    jane.address->suite = 103;
    cout << john << jane << endl;
//using factory;
    auto e = EmployeeFactory::NewMainOfficeEmployee("john", 123);
    cout << *e << endl;
}

