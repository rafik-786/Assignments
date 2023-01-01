#include <bits/stdc++.h>
using namespace std;

class Pattern {

	int size;
public:
	Pattern(int size) {
		this->size = size;
	}
	Pattern() {
		size = 0;
	}

	void setSize(int size) {
		this->size = size;
	}

	void print() {
		for (int i = 1; i <= size; i++) {

			//space
			for (int j = 1; j < i; j++) {
				cout << " ";
			}

			//star

			for (int j = 1; j <= (2 * (size - i + 1) - 1); j++) {
				// cout << j << endl;
				cout << "*";
			}

			//next line
			cout << endl;


		}
	}


};

int main() {


	Pattern p(10);
	p.print();

	return 0;
}