#include "stdafx.h"
#include "NoneLinerEquation.h"
#include <iostream>
using namespace std;
//���̶�Ӧ����f
#define f(x) (x*x*x-7.7*x*x+19.2*x-15.3)
//���̶�Ӧ����f��һ�׵���
#define f1(x) (3*x*x-15.4*x+19.2)
//ʵ���ĶԷַ����,
//ǰ��������Ϊ����Ŀ�ʼ�����
//����eΪ��������
float BalancedDiv(float start,float end,float e) {
	if (f(start)*f(end)<0)
	{
		while (abs(start-end)>e)//δ�ﵽ����������ֵ
		{
			//�е�λ���뺯��ֵ
			float midPos = (start + end) / 2;
			float midVal = f(midPos);
			//�����жϣ�������ֵ����
			if (f(start)*midVal<0)//(start~minPos ���и�)
			{
				end = midPos;
				continue;
			}
			if (f(end)*midVal<0)//(minPos~end ���и�)
			{
				start = midPos;
				continue;
			}
		}
		return (start+ end)/2;
		
	}
	cout << "err in begin" << endl;
	return -1;
}

//����������
#define MAXREPT (10000)
//ţ�ٵ��������
//��һ������Ϊ��ʼֵ
//�ڶ�������Ϊ��������
float NewTonIterate(float x0,float epsilon) {
	//f��һ�׵�����f1
	float xk = x0;
	float xk1;
	for (size_t i = 0; i < MAXREPT; i++,xk=xk1)//׼���´ε���
	{
		xk1 = xk - f(xk) / f1(xk);//���ݹ�ʽ��������
		if (abs(xk1 - xk)<epsilon)
		{
			return xk1;
		}
	}
	return xk1;
}

//�ҽط��������ţ�ٵ������Ļ����Ͻ���һ�ײ��̽��Ƶ���
//��Ҫ������ʼֵ
float Flatsawn(float x0, float x1, float epsilon) {
	//f��һ�׵�����f1
	float xk = x0;
	float xk1 = x1;
	float xk2;
	for (size_t i = 0; i < MAXREPT; i++, xk = xk1,xk1=xk2)//׼���´ε���
	{
		xk2 = xk1 - (f(xk1)*(xk1-xk)) /(f(xk1)-f(xk));//���ݹ�ʽ��������
		if (abs(xk2 - xk1)<epsilon)
		{
			return xk2;
		}
	}
	return xk1;

}