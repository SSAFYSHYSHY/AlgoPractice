#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	int k;
	string a, b;

	cin >> k >> a >> b;

	int same = 0, n = a.size();

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) same++;
	}

	int diff = n - same;

	int max_correct = min(k, same) + (diff - max(0, k - same));

	cout << max_correct;
}