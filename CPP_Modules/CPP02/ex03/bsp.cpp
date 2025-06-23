#include "Fixed.hpp"
#include "Point.hpp"

float crossProduct(Point const a, Point const b, Point const c) {
	std::pair<float, float> pA = a.getPoint();
	std::pair<float, float> pB = b.getPoint();
	std::pair<float, float> pC = c.getPoint();

	float ABx = pB.first - pA.first;
	float ABy = pB.second - pA.second;
	float ACx = pC.first - pA.first;
	float ACy = pC.second - pA.second;

	return (ABx * ACy) - (ABy * ACx);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	return ((crossProduct(a, b, point) >= 0 && crossProduct(b, c, point) >= 0 && crossProduct(c, a, point) >= 0) 
			|| (crossProduct(a, b, point) <= 0 && crossProduct(b, c, point) <= 0 && crossProduct(c, a, point) <= 0));
}

int main(void) {
	Point a = Point();
	Point b = Point(0, 1);
	Point c = Point(1, 0);

	Point target = Point(0.5f, 0.7f);
	std::cout << (bsp(a, b, c, target) == 1 ? "yes\n" : "no\n");
}