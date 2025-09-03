#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> map;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 1) {
			long long x, w;
			cin >> x >> w;

			map.insert({ w , x });
		}
		else {
			long long w;
			cin >> w;

			cout << map[w] << "\n";
		}
	}
}