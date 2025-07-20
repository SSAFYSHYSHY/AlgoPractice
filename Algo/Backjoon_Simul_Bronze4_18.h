#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, sum;
	cin >> a >> b;

	sum = a + b;

	string s = to_string(sum);

	cout << s.length();
}