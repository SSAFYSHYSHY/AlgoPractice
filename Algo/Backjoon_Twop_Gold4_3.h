#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
int arr[27] = { 0, };

int main() {
	cin >> n >> s;

	int l = 0, r = 0;
	int ans = 0;
	int curr = 0;

	while (r < s.length()) {
		if (arr[s[r] - 'a'] == 0) curr++;
		arr[s[r] - 'a']++;

		while (curr > n) {
			if (--arr[s[l] - 'a'] == 0) curr--;
			l++;
		}

		ans = max(ans, r - l + 1);
		r++;
	}
	cout << ans;
}