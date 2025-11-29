#pragma once
#include "Test.h"
#include <algorithm>

using namespace std;

class CalcEx : public Calc {
public:
	CalcEx();
	int Sub(int a, int b);
	float Sub(float a, float b);
};