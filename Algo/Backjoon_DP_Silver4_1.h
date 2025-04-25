#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}



	vector<int> v(n + 1, 1);
	vector<int> v2(n + 1, 1);

	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			v[i] = v[i - 1] + 1;
		}
		if (arr[i] <= arr[i - 1]) {
			v2[i] = v2[i - 1] + 1;
		}

		ans = max({ ans, v[i], v2[i] });
	}
	cout << ans;
}