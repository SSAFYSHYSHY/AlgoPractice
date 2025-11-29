#include "Test.h"

using namespace std;

float Calc::Add(float a, float b) {
	float ans = a + b;
	OutPut(a, " + ", b, ans);
	return ans;
}

float Calc::Sub(float a, float b) {
	float ans = a - b;
	OutPut(a, " - ", b, ans);
	return ans;
}

void Calc::OutPut(float a, string op, float b, float ans) {
	cout << "CAlc" << " : " << a << " " << op << " " << b << " = " << ans << "\n";
}