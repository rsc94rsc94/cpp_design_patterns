#include <iostream>
#include <vector>

using namespace std;
//CRTP  curously recurring template pattern
template <typename Self>
struct SomeNeurons{
    template <typename T>  void connect_to(T &other){
        for(auto &from: static_cast<Self*>(this)){
            for(auto &to: other){
                from.out.push_back(&other);
                to.in.push_back(&to);
            }
        }

    }
};

struct Neuron : public SomeNeurons<Neuron>{
    vector<Neuron*> in, out;
    unsigned int id;
    Neuron(){
        static int id{1};
        this->id = id++;
    }
    Neuron * begin() { return this; }
    Neuron * end() { return this+1; }
//    void connect_to(Neuron &other){
//        out.push_back(&other);
//        other.in.push_back(this);
//    }
    friend ostream& operator<<(ostream &os, const Neuron &obj){
        for(Neuron *n:obj.in){
            os << n->id << "\t-->\t[" << obj.id << "]" << endl;
        }

        for(Neuron *n : obj.out){
            os << "[" << obj.id << "]\t-->\t" << n->id << endl;
        }
        return os;
    }
};

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer>{
    NeuronLayer(int count){
        while(count --> 0)
            emplace_back(Neuron{});
    }

    friend ostream & operator<<(ostream&os , const NeuronLayer &obj){
        for(auto &n: obj){
            os << n ;
        }
        os << endl;
        return os;
    }
};


int main(){
    Neuron n1,n2;
    n1.connect_to(n2);//1
    cout << n1 << n2 << endl;

    NeuronLayer l1{2}, l2{3};
    //n1.connect_to(l1);//2
    //l1.connect_to(n1);//3
    //l1.connect_to(l2);//4

}
