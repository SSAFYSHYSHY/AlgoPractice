#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, E;
set<int> st[101];
int num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	while (E--) {
		int K; cin >> K;
		vector<int> vec;
		set<int> tmp;
		bool is_bard = 0;
		while (K--) {
			int x; cin >> x;
			vec.emplace_back(x);
			if (x < 2) is_bard = 1;
		}
		if (is_bard) {
			num++;
			for (auto& x : vec) st[x].insert(num);
		}
		else {
			for (auto& x : vec) {
				for (auto& xx : st[x]) tmp.insert(xx);
			}

			for (auto& x : vec) {
				for (auto& xx : tmp) st[x].insert(xx);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (st[i].size() == num) cout << i << '\n';
	}
}