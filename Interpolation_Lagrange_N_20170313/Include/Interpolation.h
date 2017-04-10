#pragma once
#include "stdafx.h"
#include "DataStruct.h"
//插值

//拉格朗日插值函数
float Lagrange(Point* src, int count, float target);

//计算差商表
float* MakeDiffQuotient(Point* src, int count);

//牛顿插值函数
float NewTon(Point* src, int count, float target);