#pragma once
#include "stdafx.h"
#include "DataStruct.h"
//��ֵ

//�������ղ�ֵ����
float Lagrange(Point* src, int count, float target);

//������̱�
float* MakeDiffQuotient(Point* src, int count);

//ţ�ٲ�ֵ����
float NewTon(Point* src, int count, float target);