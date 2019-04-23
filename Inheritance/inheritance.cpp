#include <iostream>
#include <string>


using namespace std;


// class Person{
// public:
//     int _p;
// };

// class Student : Person{
// public:
//     int _s;
// };


// int main()
// {
//     Student s;
//     s._p = 5;
//     return 0;
// }


class Person {
public:
    Person (const char* name = "Wyh")
    :_name(name)
    {
        cout << "Person()" << endl;
    }

    ~Person(){
        cout << "~Person" << endl;
    }

    Person(const Person& p)
    :_name(p._name)
    {
        cout << "Person(const Person&)" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "Person& operator=(const Person& p)" << endl;
        if(this != &p){
            _name = p._name;
        }
        return *this;
    }

    void Print_Person()
    {
        cout << "_name :" << _name << endl;
    }

private:
    string _name;
};

class Student : public Person
{
public:
    Student(const char* name = "Zty")
    :Person(name)
    ,_id(10)
    {
        cout << "Student()" << endl;
    }

    Student(const Student& s)
    :Person(s)
    ,_id(s._id)
    {
        cout << "Student(const Student& s) " << endl;
    }

    Student& operator=(const Student& s)
    {
        cout << "Student& operator=(const Student& s)" << endl;
        if(this != &s){
            Person::operator=(s);
            _id = s._id;
        }
        return *this;
    }

    ~Student()
    {
        cout << "~Student" << endl;
        //Person::~Person();
    }

    void Print_Student()
    {
        cout << "_id :" << _id << endl;
    }


private:
    int _id;
};

int main()
{
    Student s;

    Student cpy;
    cpy = s;

    return 0 ;
}