#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

struct Address{
    string street, city;
    int suite;
    Address(){}
    Address(const string &street, const string &city, int suite):
    street{street}, city{city},suite{suite}{}

    Address(const Address &add):street{add.street}, city{add.city}, suite{add.suite}{}
    friend ostream& operator<<(ostream &os, const Address &address){
        os << "street: " << address.street << " city: " << address.city
        << " suite: " << address.suite << endl;
        return os;
    }
private:
    friend class serialization::access;
    template <class archive>
    void serialize(archive &ar, const unsigned version){
        ar & street;
        ar & city;
        ar & suite;
    }
};

struct Contact{
    string name;
    Address * address;
    Contact(){}
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
private:
    friend class serialization::access;
    template <class archive>
    void serialize(archive &ar, const unsigned version){
        ar & name;
        ar & address;
    }
};


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
    auto clone = [](Contact &c){
        ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        cout << s << endl;

        istringstream iss(s);
        archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    auto john = EmployeeFactory::NewMainOfficeEmployee("john",123);
    auto jane = clone(*john);
    jane.name = "jane";
    cout << *john << jane <<endl;
}

