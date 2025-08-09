#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
int prefix[100001];
vector<int> v;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int num = arr[n - 1];
	double max_avg = 0;
	prefix[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 1; i--) {
		num = min(num, arr[i]);

		prefix[i] = prefix[i + 1] + arr[i];

		double avg = 1.0 * (prefix[i] - num) / (n - i - 1);

		if (avg >= max_avg) {
			if (avg > max_avg) {
				v.clear();
				max_avg = avg;
			}
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}