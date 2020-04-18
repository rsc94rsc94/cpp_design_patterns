#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

//class Creature{
//    int strength, agility, intelligence;
//public:
//    void set_strength(int strength){ strength = strength;}
//    int get_strength()const {return strength;}
//    void set_agility(int agility){ agility = agility; }
//    int get_agility()const { return agility; }
//    void set_intelligence(int intelligence){ intelligence  = intelligence; }
//    int get_intelligence()const { return intelligence; }
//    int sum() const{
//        return strength+agility+intelligence;
//    }
//    double avarage() const{
//        return sum()/3.0;
//    }
//    int max() const{
//        return max(max(strength,agility), intelligence);
//    }
//}


class Creature{
    enum Abilities{str, agl, intl, count};
    array<int,count> abilities;
public:
    int get_strength() const { return abilities[str];}
    void set_strength(int strength) { abilities[str] = strength; }
    int get_agility() const { return abilities[agl];}
    void set_agility(int agility) { abilities[agl] = agility; }
    int get_intelligence() const { return abilities[intl];}
    void set_intelligence(int intelligence) { abilities[intl] = intelligence; }
    int sum() const{
        return accumulate(abilities.begin(), abilities.end(),0);
    }
    double average() const {
        return sum()/(double)count;
    }
    int  max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};

int main(){
    Creature orc;
    orc.set_strength(16);
    orc.set_agility(11);
    orc.set_intelligence(9);
    cout << "The orc has an average stats of "
        << orc.average()
        << " and a maximum stats of "
        << orc.max()
        << " and total stats of "
        << orc.sum() << endl;
}
