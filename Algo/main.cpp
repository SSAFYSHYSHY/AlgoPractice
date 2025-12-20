#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long arr[300001];
long long prefix[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i]; 
	}


	for (int i = 0; i < m; i++) {
		long long a;
		cin >> a;

		if (prefix[m] < a) {
			cout << "Go away!\n";
			continue;
		}

		long long idx = lower_bound(prefix + 1, prefix + m + 1, a) - prefix;
		cout << idx << "\n";
	}


		 
}