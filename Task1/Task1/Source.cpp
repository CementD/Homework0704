#include <iostream>
using namespace std;

class Person {
    char* name;
    int age;

public:
    Person(const char* pName, int pAge) : age(pAge) {
        int length = strlen(pName);
        name = new char[length + 1];
        for (int i = 0; i <= length; i++)
            name[i] = pName[i];
    }

    Person(const Person& other) : age(other.age) {
        int length = strlen(other.name);
        name = new char[length + 1];
        for (int i = 0; i <= length; i++)
            name[i] = other.name[i];
    }

    ~Person() {
        delete[] name;
    }

    Person getOlder(const Person& other) {
        if (this->age >= other.age)
            return *this;
        else
            return other;
    }

    const char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person person1("Semen", 15);
    Person person2("Nikita", 16);

    Person olderPerson = person1.getOlder(person2);

    cout << "Older person is: " << olderPerson.getName() << ", Age: " << olderPerson.getAge() << endl;

    return 0;
}
