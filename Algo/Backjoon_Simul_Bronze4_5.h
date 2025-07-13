#pragma once
#include <iostream>

using namespace std;

long long n;

int main() {
	cin >> n;

	if (-32768 <= n && n <= 32767) {
		cout << "short";
	}
	else if (-2147483648 <= n && n <= 2147483647) {
		cout << "int";
	}
	else {
		cout << "long long";
	}

}