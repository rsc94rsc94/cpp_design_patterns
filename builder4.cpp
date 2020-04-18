
class PersonBuilder;
class PersonJobBuilder;
class PersonAddressBuilder;

class Person
{
private:
    string street_address, post_code, city;

    string company_name, position;
    int annual_income{0}
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
public:
    static PersonBuilder create();
    Person();
    ~Person();
};

class PersonAddressBuilder:

class PersonBuilderBase{
protected:
    Person &p;
public:
    PersonBuilderBase(Person &person) : person(person){}
    personAddressBuilder lives() const{
        return PersonAddressBuilder{person}
        }
    PersonJobBuilder works() const{
        return PersonJobBuilder{person}
    }
}

class PersonBuilder: PersonBuilderBase{
private:
    Person p;
public:
    PersonBuilder():PersonBuilderBase(p){}
}

