#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;
long long arr[5005];
long long maxi = 1e18;
vector<long long> v;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n - 2; i++) {
		long long s = i + 1;
		long long e = n;

		while (s < e) {
			long long sum = arr[i] + arr[s] + arr[e];

			if (abs(sum) < maxi) {
				maxi = abs(sum);
				v.clear();
				v.push_back(arr[i]);
				v.push_back(arr[s]);
				v.push_back(arr[e]);
			}

			if (sum < 0) s++;
			else e--;
		}
	}

	cout << v[0] << " " << v[1] << " " << v[2];
}