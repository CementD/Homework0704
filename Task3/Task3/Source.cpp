#include <iostream>
#include <iomanip>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    Person() : name(nullptr), age(0) {}

    Person(const char* pName, int pAge) : age(pAge) {
        int len = strlen(pName);
        name = new char[len + 1];
        for (int i = 0; i <= len; ++i)
            name[i] = pName[i];
    }

    Person(const Person& other) : age(other.age) {
        int len = strlen(other.name);
        name = new char[len + 1];
        for (int i = 0; i <= len; i++)
            name[i] = other.name[i];
    }

    ~Person() {
        delete[] name;
    }

    void setName(const char* pName) {
        int len = strlen(pName);
        name = new char[len + 1];
        for (int i = 0; i <= len; i++)
            name[i] = pName[i];
    }

    void setAge(int pAge) {
        age = pAge;
    }

    const char* getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

class Apartment {
private:
    Person residents[3];
    int numberOfResidents;

public:
    Apartment() : numberOfResidents(3) {}

    Person& getResident(int index) {
        return residents[index];
    }

    int getNumberOfResidents() {
        return numberOfResidents;
    }
};

int main() {
    Apartment apartment;

    apartment.getResident(0).setName("Semen");
    apartment.getResident(0).setAge(15);
    apartment.getResident(1).setName("Nikita");
    apartment.getResident(1).setAge(16);
    apartment.getResident(2).setName("Kiril");
    apartment.getResident(2).setAge(14);

    cout << "Resident" << setw(10) << "Name" << setw(10) << "Age" << endl;
    for (int i = 0; i < apartment.getNumberOfResidents(); i++) {
        cout << setw(5) << i + 1 << setw(14) << apartment.getResident(i).getName() << setw(8) << apartment.getResident(i).getAge() << endl;
    }

    return 0;
}
