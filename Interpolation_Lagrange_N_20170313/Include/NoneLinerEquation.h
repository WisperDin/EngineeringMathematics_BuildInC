#pragma once
#include "stdafx.h"

//非线性方程求根

//实根的对分法求解,
//前两个参数为区间的开始与结束
//参数e为误差控制量
float BalancedDiv(float start, float end, float e);

//牛顿迭代法求根
//第一个参数为初始值
//第二个参数为误差控制量
float NewTonIterate(float x0, float epsilon);

//弦截法求根，在牛顿迭代法的基础上将用一阶差商近似导数
//需要两个初始值
float Flatsawn(float x0, float x1, float epsilon);