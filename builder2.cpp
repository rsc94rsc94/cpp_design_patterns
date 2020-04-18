#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

class HtmlBuilder;
class HtmlElement
{
public:
	string name, text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;
	HtmlElement(const string &name, const string &text):name(name),text(text){}
    HtmlElement(){}
	string str(const int indent = 0) const{
        ostringstream oss;
        string i = string(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if(text.size() > 0)
            oss << string(indent_size*(indent+1),' ') << text << endl;
        for(auto &e:elements){
            oss << e.str(indent+1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
	}
	static HtmlBuilder build(string root_name);

};

class HtmlBuilder
{
public:
    HtmlElement root;

    HtmlBuilder(string root_name){
        root.name = root_name;
    }
    HtmlBuilder& add_child(string child_name, string child_text){
        HtmlElement e{child_name,child_text};
        root.elements.emplace_back(e);
        return *this;
    }
    string str() const{
       return root.str();
    }

    operator HtmlElement() const {
        //return move(root);
        return root;
    }
};
HtmlBuilder HtmlElement:: build(string root_name){
        HtmlBuilder b{root_name};
        return b;
	}


int main(){
    HtmlBuilder builde("ul");
    builde.add_child("li", "hello").add_child("li", "world");
    cout << builde.str() << endl;

    auto builder = HtmlElement::build("ul").add_child("li", "hello").add_child("li", "world");
    HtmlElement e = HtmlElement::build("ul").add_child("li", "hello").add_child("li", "world");
    cout << builder.str() << endl;
    cout << e.str() << endl;
}
