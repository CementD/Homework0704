#include <iostream>
using namespace std;

class Flat {
	int floor;
	int size;
public:
	Flat(int pFloor, int pSize) : floor(pFloor), size(pSize) {
		cout << "Flat Parametrized constructor\n";
	}

	Flat(const Flat& other) : floor(other.floor), size(other.size) {
		cout << "Point Copy constructor\n";
	}

	int getFloor() {
		return floor;
	}

	int getSize() {
		return size;
	}
};

int main() {
	Flat flat1(2, 1000);
	Flat flat2(flat1); 
	cout << "Flat is on the " << flat2.getFloor() << " floor; Size: " << flat2.getSize() << " m2";
	return 0;
}