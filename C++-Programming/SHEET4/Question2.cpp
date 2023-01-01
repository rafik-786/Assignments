#include <bits/stdc++.h>
using namespace std;

class Triangle {

private:
	float a, b, c;
	float area, perimeter;
public:
	Triangle() {
		a = 0;
		b = 0;
		c = 0;
		area = 0;
		perimeter = 0;
	}
	void setSide(void);
	void printData(void);

	void calculatePerimeter(void) {
		this->perimeter = a + b + c;
	}
	void calculateArea(void) {
		calculatePerimeter();
		float s = this->perimeter / 2.0;
		this->area = sqrt(s * (s - a) * (s - b) * (s - c));
	}

};

void Triangle::setSide(void) {
	cin >> this->a;
	cin >> this->b;
	cin >> this->c;
}

void Triangle::printData(void) {
	cout << "Perimeter:\t" << this->perimeter;
	cout << endl;
	cout << "Area:\t" << this->area;

}


int main() {

	Triangle t;
	t.setSide();
	t.calculatePerimeter();
	t.calculateArea();
	t.printData();

	return 0;
}