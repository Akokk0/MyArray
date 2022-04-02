#include <iostream>
#include "MyArray.hpp"

class Person {

private:

    int m_age;
    string m_name;

public:

    Person() {}
    Person(int age, string name) {

        m_age = age;
        m_name = name;

    }

    friend ostream &operator<<(ostream &os, const Person &person) {

        os << "m_age: " << person.m_age << " m_name: " << person.m_name;

        return os;

    }

    virtual ~Person(){}

};

int main() {

    Person p1(18, "张三");
    Person p2(19, "李四");
    Person p3(20, "王五");

    MyArray<Person> array(5);

    array.pushBack(p1);
    array.pushBack(p2);
    array.pushBack(p3);

    for (int i = 0; i < array.getMSize(); ++i) {

        cout << array.m_pAddress[i] << endl;

    }

    return 0;
}
