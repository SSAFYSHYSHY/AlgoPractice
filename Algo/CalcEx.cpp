#include "Test2.h"
#include <iostream>

using namespace std;

CalcEx::CalcEx() {
	name = "Sub";

}

int CalcEx::Sub(int a, int b) {
	return a - b;
}

float CalcEx::Sub(float a, float b) {
	return a - b;
}