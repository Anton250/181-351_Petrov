#include "stdafx.h"
#include "discr.h"
#include <math.h>
#include <iostream>
/* 
*/

double dicr(double a, double b, double c)
{
	double D;
	D = (b * b) - (4 * a*c);
	return D;
}

pair quadratic_equation(double a, double b, double c)
{
	double D, x1, x2;
	D = dicr(a, b, c);
	if (D > 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		return { x1, x2 };
	}
	else if (D == 0) {
		x1 = -b / (2 * a);
		return { x1, x1 };
	}
	else if (D < 0) {
		return { 0, 0 };
	}
	
}
