
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
#include <gtest/gtest.h>

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


struct SingletRecordFinder{
    int total_population(vector<string> names){
        int result{0};
        for(auto &name: names){
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};

TEST(RecordFinderTest, SinglenTotalPopulationTest){
    SingletRecordFinder rf;
    vector<string> names{"Seoul" , "Mexico City"};
    int tp = rf.total_population(names);
    EXPECT_EQ(17500+17400, tp);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
