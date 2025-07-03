#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t, a, b;
	cin >> t;



	while (t--) {
		cin >> a >> b;

		vector<int> v1, v2;

		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}

		while (a > 0) {
			v1.push_back(a);
			a /= 2;
		}
		while (b > 0) {
			v2.push_back(b);
			b /= 2;
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int ans = 1;
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[i]) {
				ans = v1[i];
			}
		}

		cout << ans * 10 << "\n";
	}

}