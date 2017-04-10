#include "stdafx.h"
#include "NoneLinerEquation.h"
#include <iostream>
using namespace std;
//方程对应函数f
#define f(x) (x*x*x-7.7*x*x+19.2*x-15.3)
//方程对应函数f的一阶导数
#define f1(x) (3*x*x-15.4*x+19.2)
//实根的对分法求解,
//前两个参数为区间的开始与结束
//参数e为误差控制量
float BalancedDiv(float start,float end,float e) {
	if (f(start)*f(end)<0)
	{
		while (abs(start-end)>e)//未达到误差控制量的值
		{
			//中点位置与函数值
			float midPos = (start + end) / 2;
			float midVal = f(midPos);
			//折中判断（根据中值定理）
			if (f(start)*midVal<0)//(start~minPos 内有根)
			{
				end = midPos;
				continue;
			}
			if (f(end)*midVal<0)//(minPos~end 内有根)
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

//最大运算次数
#define MAXREPT (10000)
//牛顿迭代法求根
//第一个参数为初始值
//第二个参数为误差控制量
float NewTonIterate(float x0,float epsilon) {
	//f的一阶导数叫f1
	float xk = x0;
	float xk1;
	for (size_t i = 0; i < MAXREPT; i++,xk=xk1)//准备下次迭代
	{
		xk1 = xk - f(xk) / f1(xk);//根据公式迭代计算
		if (abs(xk1 - xk)<epsilon)
		{
			return xk1;
		}
	}
	return xk1;
}

//弦截法求根，在牛顿迭代法的基础上将用一阶差商近似导数
//需要两个初始值
float Flatsawn(float x0, float x1, float epsilon) {
	//f的一阶导数叫f1
	float xk = x0;
	float xk1 = x1;
	float xk2;
	for (size_t i = 0; i < MAXREPT; i++, xk = xk1,xk1=xk2)//准备下次迭代
	{
		xk2 = xk1 - (f(xk1)*(xk1-xk)) /(f(xk1)-f(xk));//根据公式迭代计算
		if (abs(xk2 - xk1)<epsilon)
		{
			return xk2;
		}
	}
	return xk1;

}