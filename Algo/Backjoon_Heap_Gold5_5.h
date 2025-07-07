#pragma once
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

long long q, n, k, b, c, idx = 0, ans = 0;
unordered_map<string, int> map;
priority_queue<long long> pq[100001];
string s;

int main() {
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> n >> s;

		if (map.find(s) == map.end()) {
			map[s] = idx++;
		}

		if (n == 1) {
			cin >> k;

			for (int j = 0; j < k; j++) {
				cin >> c;
				pq[map[s]].push(c);
			}
		}
		else if (n == 2) {
			cin >> b;

			auto& curr = pq[map[s]];

			for (int j = 0; j < b && !curr.empty(); j++) {
				ans += curr.top();
				curr.pop();
			}
		}
	}

	cout << ans;
}