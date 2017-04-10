#include "stdafx.h"
#include "Fitting.h"
#include <iostream>

//线性最小二乘法
void LinerLeastSquare(Point src[], int n)
{
	double sumxy = 0, sumx = 0, sumy = 0, sumxx = 0;
	for (int i = 0; i < n; i++)
	{
		sumxy += src[i].x * src[i].y;
		sumx += src[i].x;
		sumy += src[i].y;
		sumxx += src[i].x * src[i].x;
	}
	double b1 = 0, b2 = 0, base = 0;
	base = n*sumxx - sumx*sumx;//分母
	b2 = (n*sumxy - sumx*sumy) / base;
	b1 = (sumxx*sumy - sumx*sumxy) / base;
	std::cout << "y=" << b1 << "+" << b2 << "x";
}

