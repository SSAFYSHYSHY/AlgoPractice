#pragma once
#include <iostream>

using namespace std;

int main() {
	int N;
	int ans = 0;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int sum = 0;
		int num = i;

		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == N) {
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}