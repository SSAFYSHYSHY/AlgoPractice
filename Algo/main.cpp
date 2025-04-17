#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 21e8;
vector<int> v;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int l = 0, r = (v.size() - 1);

	while (l < r) {
		int sum = v[l] + v[r];

		if (abs(sum) < abs(ans)) {
			ans = sum;
		}

		if (sum == 0) break;
		else if (sum < 0) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << ans;


}