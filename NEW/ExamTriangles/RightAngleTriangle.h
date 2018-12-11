//
// Created by admin on 04.12.2018.
//

#ifndef EXAMTASKLAST_RIGHTTRIANGLE_H
#define EXAMTASKLAST_RIGHTTRIANGLE_H


#include "Triangle.h"

const int DEFAULT_A_LENGTH = 3;
const int DEFAULT_B_LENGTH = 4;
const int DEFAULT_C_LENGTH = 5;

class RightAngleTriangle : public Triangle {
private:
    void correctHypotenuse();
public:
    RightAngleTriangle();
    RightAngleTriangle(double cathetusA, double cathetusB);
    double getArea();
    double getRadiusOfInCircle();
    double getRadiusOfOutCircle();
    void increaseLengthOfA(double value);
    void increaseLengthOfB(double value);
    void show();

};


#endif //EXAMTASKLAST_RIGHTTRIANGLE_H
