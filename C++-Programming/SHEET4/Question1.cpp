#include <bits/stdc++.h>
using namespace std;
# define M_PI 3.14159265358979323846

class Area {
protected:
	float area;
	void calculateArea(void);
	int getArea(void);
};


class Circle: public Area {

private:
	float radius;

public:

	Circle(int radius) {
		this->radius = radius;
	}
	Circle() {}

	void setRadius(float radius) {
		this->radius = radius;
	}

	float getRadius(void) {
		return this->radius;
	}
	void calculateArea(void) {
		this->area = M_PI * radius * radius;
	}

	float getArea(void) {
		return this->area;
	}


};


int main() {

	Circle c;
	c.setRadius(12);
	c.calculateArea();
	cout << c.getArea() << endl;

	return 0;
}