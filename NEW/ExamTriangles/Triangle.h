//
// Created by admin on 04.12.2018.
//

#ifndef EXAMTASKLAST_TRIANGLE_H
#define EXAMTASKLAST_TRIANGLE_H

const int DEFAULT_LENGTH = 1;

class Triangle {
    // для доступа полей в потомках указываем protected
protected:
    double a, b, c;
public:
    Triangle();

    Triangle(double a, double b, double c);

    ~Triangle();

    double getA();

    double getB();

    double getC();

    void setA(double a);

    void setB(double b);

    void setC(double c);

    virtual void increaseLengthOfA(double value);

    virtual void increaseLengthOfB(double value);

    void increaseLengthOfC(double value);

    double getPerimeter();

    virtual double getArea();

    virtual double getRadiusOfInCircle();

    virtual double getRadiusOfOutCircle();

    virtual void show();

};


#endif //EXAMTASKLAST_TRIANGLE_H
