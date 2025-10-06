#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans = 0;
vector<int> v, v1;

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num < 10) continue;
		else if (num == 10) ans++;

		//10ÀÇ ¹è¼ö.
		else if (num % 10 == 0) v.push_back(num);
		else v1.push_back(num);
	}

	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());

	v.insert(v.end(), v1.begin(), v1.end());

	while (k > 0 && !v.empty()) {
		int num = v[0];
		int cut = num / 10;

		if (num % 10 == 0) {
			if (cut - 1 <= k) {
				ans += cut;
				k -= (cut - 1);
			}
			else {
				ans += k;
				break;
			}
		}
		else {
			if (cut <= k) {
				ans += cut;
				k -= cut;
			}
			else {
				ans += k;
				break;
			}

		}

		v.erase(v.begin());
	}

	cout << ans;
}