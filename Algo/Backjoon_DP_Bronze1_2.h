#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long dp[100001] = { 0, };

long long n, ans = 0;
string s;

int main() {
	cin >> n >> s;

	int maxl = 0;
	int currl = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (s[i] == 'a' || s[i] == 'h') currl = 1;
			else currl = 0;
		}
		else {
			if ((s[i - 1] == 'a' && s[i] == 'h') || (s[i - 1] == 'h' && s[i] == 'a')) {
				currl++;
			}
			else {
				if (s[i] == 'a' || s[i] == 'h') currl = 1;
				else currl = 0;
			}
		}

		maxl = max(maxl, currl);

	}

	cout << maxl;
}