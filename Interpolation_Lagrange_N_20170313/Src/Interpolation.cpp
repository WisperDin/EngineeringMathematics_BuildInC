#include "stdafx.h"
#include "Interpolation.h"
//�������ղ�ֵ����
float Lagrange(Point* src, int count, float target) {
	float temp;//��ʾ������
	float result = 0;//���ձ��ʽ
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
//�γɲ��̱�
float* MakeDiffQuotient(Point* src, int count) {//�����countָ���ǲ�ֵ������� n+1����ֵ��ʱ��Ҫn�ײ���
	float *diffQuo = new float[count];
	//init ��ʼ��
	for (size_t i = 0; i < count; i++)
	{
		diffQuo[i] = src[i].y;
	}

	//����k�ײ���
	for (int k = 1; k < count; k++)
	{
		for (int j = count - 1; j >= k; j--)
		{
			diffQuo[j] = (diffQuo[j] - diffQuo[j - 1]) / (src[j].x - src[j - k].x);
		}
	}
	return diffQuo;
	//����������̱�
	//for (size_t i = 0; i < count; i++)
	//{
	//	cout << diffQuo[i] << endl;
	//}

}
//ţ�ٲ�ֵ����
float NewTon(Point* src, int count, float target) {
	float *diffQuo = MakeDiffQuotient(src, count);//��ò��̱�
												  //��ʼ
	float t = 1;
	float newTon = src[0].y;
	//��ʼ��������
	for (size_t i = 1; i < count; i++)
	{
		t = (target - src[i - 1].x)*t;
		newTon += t*diffQuo[i];
	}
	//���ؽ��
	return newTon;
}