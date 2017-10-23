# 09-712-2

```C++
// Task01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	// границы интегрирования
	double a, b;
	// количество прямоугольников/отрезков/разбиений
	int n;

	cin >> a >> b >> n;

	double h = fabs(b - a) / n;

	double integral = 0;
	/*
	double x = a;
	while (x <= b)
	{
		integral = integral + sin(2 * x) * h;
		x = x + h;
	}
	*/

	for (double x = a; x <= b; x = x + h)
	{
		integral = integral + sin(2 * x) * h;
	}

	cout << setprecision(15) << integral;
	// 1.5707963267948966192313215
	// 3.1415926535897932384626433
	return 0;
}
```

ДЗ - реализовать методом Симпсона.

Формула со слов:
https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%A1%D0%B8%D0%BC%D0%BF%D1%81%D0%BE%D0%BD%D0%B0
Также формулу можно записать используя только известные значения функции, то есть значения в узлах:
