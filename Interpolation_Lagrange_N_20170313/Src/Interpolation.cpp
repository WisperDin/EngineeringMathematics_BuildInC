#include "stdafx.h"
#include "Interpolation.h"
//拉格朗日插值函数
float Lagrange(Point* src, int count, float target) {
	float temp;//表示基函数
	float result = 0;//最终表达式
	for (int i = 0; i < count; i++)
	{
		temp = 1.f;
		for (int j = 0; j < count; j++)
		{
			if (i != j)
			{
				temp *= ((target - src[j].x) / (src[i].x - src[j].x));
			}
		}
		result += temp*src[i].y;
	}
	return result;
}
//形成差商表
float* MakeDiffQuotient(Point* src, int count) {//这里的count指的是插值点的数量 n+1个插值点时需要n阶差商
	float *diffQuo = new float[count];
	//init 初始化
	for (size_t i = 0; i < count; i++)
	{
		diffQuo[i] = src[i].y;
	}

	//计算k阶差商
	for (int k = 1; k < count; k++)
	{
		for (int j = count - 1; j >= k; j--)
		{
			diffQuo[j] = (diffQuo[j] - diffQuo[j - 1]) / (src[j].x - src[j - k].x);
		}
	}
	return diffQuo;
	//测试输出差商表
	//for (size_t i = 0; i < count; i++)
	//{
	//	cout << diffQuo[i] << endl;
	//}

}
//牛顿插值函数
float NewTon(Point* src, int count, float target) {
	float *diffQuo = MakeDiffQuotient(src, count);//获得差商表
												  //初始
	float t = 1;
	float newTon = src[0].y;
	//开始迭代计算
	for (size_t i = 1; i < count; i++)
	{
		t = (target - src[i - 1].x)*t;
		newTon += t*diffQuo[i];
	}
	//返回结果
	return newTon;
}