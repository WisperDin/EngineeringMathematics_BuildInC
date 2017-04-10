// Interpolation_Lagrange_N_20170313.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Interpolation.h"
#include "Fitting.h"
#include "NoneLinerEquation.h"
using namespace std;
//拉格朗日插值
void CalLagrange() {
	//P15 例1.2
	//Point point[4] = { {-2.0f,17.0f},{0.0f,1.0f},{1.0f,2.0f},{2.0f,17.0f} };
	Point point[3] = { { 11.f,0.190809f },{ 12.f,0.207912f },{ 13.f,0.224915f } };
	cout << Lagrange(point, 3, 11.5);
}
//牛顿插值
void CalNewTon() {
	//P25 例1.7
	Point pointToMakeDiffQuo[4] = { { -2,17 },{ 0,1 },{ 1,2 },{ 2,19 } };
	//MakeDiffQuotient(pointToMakeDiffQuo, 4);
	cout << NewTon(pointToMakeDiffQuo, 4, 0.9) << endl;
}
//计算最小二乘法
void CalLinerLeastSquare() {

	Point point[6] = { { 0.5,1.75 },{ 1.0,2.45 },{ 1.5,3.81 },{ 2.0,4.8 },{ 2.5,7.0 },{ 3.0,8.6 } };
	LinerLeastSquare(point, 6);
}
//求根问题
void CalEq() {
	//计算对分法求实根
	cout<<"Balance Div result:"<< BalancedDiv(1, 2, 0.001)<<endl;
	//牛顿迭代法求根
	cout << "NewTon Iter result:" << NewTonIterate(1, 0.01) << endl;
	//弦截法求根
	cout << "Flatsawn result:" << Flatsawn(1.5,4.0, 0.01) << endl;
}

int main()
{
	//CalLagrange();
	//CalLinerLeastSquare();
	CalEq();
    return 0;
}

