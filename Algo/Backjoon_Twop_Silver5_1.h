#include <iostream>
#include <vector>

using namespace std;

int n, p, c;

int main() {
	cin >> n >> p >> c;
	vector<int> cow(p, 0);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		cow[x]++;
	}

	int l = 1, r = 1;
	int cnt = cow[1];
	int ans = 0;

	while (r <= p - 1) {
		if (cnt <= c) {
			ans = max(ans, r - l + 1);
			r++;

			if (r <= p - 1) {
				cnt += cow[r];
			}

		}
		else {
			cnt -= cow[l];
			l++;
		}
	}

	cout << ans;
}