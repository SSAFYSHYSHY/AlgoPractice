#include <iostream>
#include "Test.h"
#include "Test2.h"

using namespace std;

int main() {
	Calc calc;
	CalcEx calcEx;

	cout << calc.GetName() << " ";
	cout << "And " << calcEx.GetName() << "\n";

	float a, b;

	while (1) {
		cout << "Input ";
		
		cin >> a >> b;

		if (a == 0 || b == 0) break;

		int x = a;
		int y = b;

		if (x == a && y == b) {
			int ans = calc.Add(x, y);
			int ans2 = calcEx.Sub(x, y);
			cout << ans << " " << ans2 << "\n";
		}
		else {
			float ans = calc.Add(a, b);
			float ans2 = calcEx.Sub(a, b);
			cout << ans << " " << ans2 << "\n";
		}
	}
}