#include <bits/stdc++.h>
using namespace std;

class Complex {

	int real;
	int imag;
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(Complex &c) {
		this->real = c.getReal();
		this->imag = c.getImag();
	}
	Complex(int real, int imag) {
		this->real = real;
		this->imag = imag;
	}

	int getReal(void) {return real;}
	int getImag(void) {return imag;}

	void sum(Complex c) {
		this->real += c.getReal();
		this->imag += c.getImag();
	}
	void show(void) {
		cout.setf(ios::showpos);
		cout << real << imag << "i\n";
		cout.unsetf(ios::showpos);
	}
};


int main() {

	Complex c1(1, -2);
	Complex c2(c1);

	c1.sum(c2);

	c1.show();


	return 0;
}