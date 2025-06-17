#pragma once
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt = 0;
	string ans = s;

	for (int i = 0; i < n / 2; i++) {
		int j = n - i - 1;

		if (ans[i] != ans[j]) {
			cnt++;

			char mini = min(ans[i], ans[j]);
			ans[i] = ans[j] = mini;
		}
	}

	cout << cnt << "\n" << ans;
}