#pragma once
#include "stdafx.h"

//�����Է������

//ʵ���ĶԷַ����,
//ǰ��������Ϊ����Ŀ�ʼ�����
//����eΪ��������
float BalancedDiv(float start, float end, float e);

//ţ�ٵ��������
//��һ������Ϊ��ʼֵ
//�ڶ�������Ϊ��������
float NewTonIterate(float x0, float epsilon);

//�ҽط��������ţ�ٵ������Ļ����Ͻ���һ�ײ��̽��Ƶ���
//��Ҫ������ʼֵ
float Flatsawn(float x0, float x1, float epsilon);