#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string s;
	cin >> s;

	char curr = 'A';
	int total = 0;

	for (char c : s) {
		int dir = abs(c - curr);
		int rotate = min(dir, 26 - dir);
		total += rotate;
		curr = c;
	}

	cout << total;
}