#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[26];

bool cmp(int& a, int& b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int pow = 1;

		for (int j = s.length() - 1; j >= 0; j--) {
			arr[s[j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(arr, arr + 26, cmp);

	int num = 9, ans = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			break;
		}

		ans += arr[i] * num--;
	}

	cout << ans;

}