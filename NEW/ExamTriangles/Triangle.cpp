//
// Created by admin on 04.12.2018.
//

#include <cmath>
#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle() {
    this->a = DEFAULT_LENGTH;
    this->b = DEFAULT_LENGTH;
    this->c = DEFAULT_LENGTH;
}

Triangle::Triangle(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::getA() {
    return this->a;
}

double Triangle::getB() {
    return this->b;
}

double Triangle::getC() {
    return this->c;
}

void Triangle::setA(double a) {
    this->a = a;
}

void Triangle::setB(double b) {
    this->b = b;
}

void Triangle::setC(double c) {
    this->c;
}

void Triangle::increaseLengthOfA(double value) {
    this->a += value;
}

void Triangle::increaseLengthOfB(double value) {
    this->b += value;
}

void Triangle::increaseLengthOfC(double value) {
    this->c += value;
}

double Triangle::getPerimeter() {
    return this->a + this->b + this->c;
}

double Triangle::getArea() {
    double halfPerimeter = getPerimeter() * 0.5;
    return sqrt(halfPerimeter *
                        (halfPerimeter - this->a) *
                        (halfPerimeter - this->b) *
                        (halfPerimeter - this->c));

}

double Triangle::getRadiusOfInCircle() {
    return 2 * getArea() / getPerimeter();
}

double Triangle::getRadiusOfOutCircle() {
    return this->a * this->b * this->c / (4 * getArea());
}

void Triangle::show() {
    cout << "AB= " << this->a << endl;
    cout << "AC= " << this->b << endl;
    cout << "BC= " << this->c << endl;
}

Triangle::~Triangle() = default;


