#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N;
map<string, int> mp;
vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string s; int x; cin >> s >> x;
		if (mp.count(s)) mp[s] += x;
		else mp.insert(make_pair(s, x));
	}

	for (auto& p : mp) vec.emplace_back(p.second);
	int N = vec.size();
	for (int i = 0; i < N; i++) {
		int xx = vec[i] * 1618 / 1000;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int y = vec[j];
			if (xx == y) {
				cout << "Delicious!";
				return 0;
			}
		}
	}

	cout << "Not Delicious...";
}