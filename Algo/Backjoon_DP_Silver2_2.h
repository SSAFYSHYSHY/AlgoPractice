#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[1001];
int arr[1001];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp(n + 1, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int answer = *max_element(dp.begin(), dp.end());

	cout << answer;
}