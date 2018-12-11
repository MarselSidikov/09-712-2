#include <iostream>
#include "Triangle.h"
#include "RightAngleTriangle.h"

using namespace std;

int main() {

    Triangle triangle;

    triangle.show();
    cout << "radius = " << triangle.getRadiusOfInCircle() << endl;
    cout << "Radius = " << triangle.getRadiusOfOutCircle() << endl;

    RightAngleTriangle rightAngleTriangle;

    rightAngleTriangle.show();

    cout << "radius = " << rightAngleTriangle.getRadiusOfInCircle() << endl;

    cout << "Radius = " << rightAngleTriangle.getRadiusOfOutCircle() << endl;

    Triangle triangle1(3, 5, 7);

    triangle1.show();

    cout << "perimeter triangle1 = " << triangle1.getPerimeter() << endl;

    triangle1.increaseLengthOfA(1);
    triangle1.show();

    cout << "perimeter triangle1 = " << triangle1.getPerimeter() << endl;

    RightAngleTriangle rightAngleTriangle1(5, 7);

    rightAngleTriangle1.show();

    cout << "radius = " << rightAngleTriangle1.getRadiusOfInCircle() << endl;

    cout << "Radius = " << rightAngleTriangle1.getRadiusOfOutCircle() << endl;

    cout << "perimeter rightAngleTriangle1 = " << rightAngleTriangle1.getPerimeter() << endl;

    cout << "square rightAngleTriangle1 = " << rightAngleTriangle1.getArea() << endl;

    rightAngleTriangle1.increaseLengthOfA(2);

    rightAngleTriangle1.show();

    return 0;
}