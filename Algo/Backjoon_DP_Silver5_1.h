#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string dp[10001];
int n;

string Calc(string a, string b) {
	int num = 0;
	int carry = 0;
	string ans = "";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() < b.length()) {
		a += "0";
	}

	while (b.length() < a.length()) {
		b += "0";
	}

	for (int i = 0; i < a.length(); i++) {
		num = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
		ans += to_string(num);
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
	}

	if (carry > 0) {
		ans += to_string(carry);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	cin >> n;
	dp[0] = "0";
	dp[1] = "1";
	dp[2] = "1";

	for (int i = 3; i <= n; i++) {
		dp[i] = Calc(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n];
}