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

class SingletonDatabase
{
private:
    SingletonDatabase(){
        cout << "Initializing data base..." <<endl;
        std::ifstream ifs("capitals.txt");
        string s,s2;
        while(getline(ifs,s)){
            getline(ifs,s2);
            cout << s << endl << s2 << endl;
            int pop = stoi(s2);
            capitals[s] = pop;
        }
    }
    map<string, int> capitals;
public:
    SingletonDatabase(SingletonDatabase &)  = delete;
    void operator=(SingletonDatabase &)  = delete;
    static SingletonDatabase& get(){
        static SingletonDatabase db;
        return db;
    }
    int get_population(const string &name){
        return capitals[name];
    }
public:
     ~SingletonDatabase(){}

};


int main(){
    string city  = "Tokyo";
    int population  = SingletonDatabase::get().get_population(city);
    cout<< "city: " << city << " Population: " << population << endl;
    population = SingletonDatabase::get().get_population("Jakarta");

}
