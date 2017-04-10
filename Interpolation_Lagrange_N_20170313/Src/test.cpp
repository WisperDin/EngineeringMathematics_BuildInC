// Interpolation_Lagrange_N_20170313.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Interpolation.h"
#include "Fitting.h"
#include "NoneLinerEquation.h"
using namespace std;
//�������ղ�ֵ
void CalLagrange() {
	//P15 ��1.2
	//Point point[4] = { {-2.0f,17.0f},{0.0f,1.0f},{1.0f,2.0f},{2.0f,17.0f} };
	Point point[3] = { { 11.f,0.190809f },{ 12.f,0.207912f },{ 13.f,0.224915f } };
	cout << Lagrange(point, 3, 11.5);
}
//ţ�ٲ�ֵ
void CalNewTon() {
	//P25 ��1.7
	Point pointToMakeDiffQuo[4] = { { -2,17 },{ 0,1 },{ 1,2 },{ 2,19 } };
	//MakeDiffQuotient(pointToMakeDiffQuo, 4);
	cout << NewTon(pointToMakeDiffQuo, 4, 0.9) << endl;
}
//������С���˷�
void CalLinerLeastSquare() {

	Point point[6] = { { 0.5,1.75 },{ 1.0,2.45 },{ 1.5,3.81 },{ 2.0,4.8 },{ 2.5,7.0 },{ 3.0,8.6 } };
	LinerLeastSquare(point, 6);
}
//�������
void CalEq() {
	//����Էַ���ʵ��
	cout<<"Balance Div result:"<< BalancedDiv(1, 2, 0.001)<<endl;
	//ţ�ٵ��������
	cout << "NewTon Iter result:" << NewTonIterate(1, 0.01) << endl;
	//�ҽط����
	cout << "Flatsawn result:" << Flatsawn(1.5,4.0, 0.01) << endl;
}

int main()
{
	//CalLagrange();
	//CalLinerLeastSquare();
	CalEq();
    return 0;
}

