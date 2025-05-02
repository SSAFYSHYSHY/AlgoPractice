#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, t;
int arr[1000001];
int ans = 21e8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		memset(arr, 0, sizeof(arr));
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);

		int cnt = 0, ans = 21e8;
		int l = 0, r = n - 1;

		while (l < r) {
			int l_n = arr[l];
			int r_n = arr[r];

			if (l_n + r_n == k) {
				l++;
				r--;
			}
			else if (l_n + r_n > k) {
				r--;
			}
			else {
				l++;
			}

			if (abs(k - (l_n + r_n)) < ans) {
				ans = abs(k - (l_n + r_n));
				cnt = 1;
			}
			else if(abs(k - (l_n + r_n)) == ans){
				cnt++;
			}
		}

		cout << cnt << '\n';
	}
}