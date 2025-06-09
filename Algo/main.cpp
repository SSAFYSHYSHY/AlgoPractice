#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;

	for (int t = 1; t <= k; t++) {
		int n, w, e;
		cin >> n >> w >> e;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			int lw_w, lw_e, le_w, le_e;
			cin >> lw_w >> lw_e >> le_w >> le_e;

			int west = w * lw_w + e * le_w;
			int east = w * lw_e + e * le_e;

			ans += max(west, east);
		}

		cout << "Data set " << t << ":\n";
		cout << ans << "\n\n";
	}


}