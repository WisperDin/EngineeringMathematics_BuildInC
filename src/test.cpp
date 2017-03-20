// Interpolation_Lagrange_N_20170313.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Interpolation.h"
using namespace std;
void CalLagrange() {
	//P15 例1.2
	//Point point[4] = { {-2.0f,17.0f},{0.0f,1.0f},{1.0f,2.0f},{2.0f,17.0f} };
	Point point[3] = { { 11.f,0.190809f },{ 12.f,0.207912f },{ 13.f,0.224915f } };
	cout << Lagrange(point, 3, 11.5);
}
void CalNewTon() {
	//P25 例1.7
	Point pointToMakeDiffQuo[4] = { { -2,17 },{ 0,1 },{ 1,2 },{ 2,19 } };
	//MakeDiffQuotient(pointToMakeDiffQuo, 4);
	cout << NewTon(pointToMakeDiffQuo, 4, 0.9) << endl;
}
int main()
{
	CalLagrange();

    return 0;
}

