//
// Created by admin on 04.12.2018.
//

#include <cmath>
#include <iostream>
#include "RightAngleTriangle.h"

using namespace std;

RightAngleTriangle::RightAngleTriangle() {
    this->a = DEFAULT_A_LENGTH;
    this->b = DEFAULT_B_LENGTH;
    this->c = DEFAULT_C_LENGTH;
}

RightAngleTriangle::RightAngleTriangle(double cathetusA, double cathetusB) {
    this->c = sqrt(cathetusA * cathetusA + cathetusB * cathetusB);
}

double RightAngleTriangle::getArea() {
    return this->a * this->b / 2;
}

double RightAngleTriangle::getRadiusOfInCircle() {
    return 0.5 * getPerimeter() - c;
}

double RightAngleTriangle::getRadiusOfOutCircle() {
    return c / 2;
}

void RightAngleTriangle::correctHypotenuse() {
    this->c = sqrt(this->a * this->a + this->b * this->b);
}

void RightAngleTriangle::increaseLengthOfA(double value) {
    this->a += value;
    correctHypotenuse();
}

void RightAngleTriangle::increaseLengthOfB(double value) {
    this->b += value;
    correctHypotenuse();
}

void RightAngleTriangle::show() {
    cout << " cathetus AB= " << a << endl;
    cout << " cathetus AC = " << b << endl;
    cout << " hypotenuse BC =" << c << endl;
}
