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

Также формулу можно записать используя только известные значения функции, то есть значения в узлах:
{\displaystyle {\int \limits _{a}^{b}f(x)dx}\approx {\frac {h}{3}}\cdot \sum _{k=1,2}^{N-1}\left[f(x_{k-1})+4f(x_{k})+f(x_{k+1})\right]} {\int \limits _{a}^{b}f(x)dx}\approx {\frac  {h}{3}}\cdot \sum _{{k=1,2}}^{{N-1}}\left[f(x_{{k-1}})+4f(x_{k})+f(x_{{k+1}})\right]
где {\displaystyle k=1,2} k=1,2 означает что индекс меняется от единицы с шагом, равным двум.
