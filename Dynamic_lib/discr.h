#pragma once
struct pair
{
	double x1;
	double x2;
};
extern "C" __declspec(dllexport) double dicr(double a, double b, double c); 
extern "C" __declspec(dllexport) pair quadratic_equation(double a, double b, double c);