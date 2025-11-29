#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
	string univ;
	string name;
	int solved;
	int penalty;
};

bool cmp(const Node& a, const Node& b) {
	if (a.solved != b.solved) return a.solved > b.solved;
	return a.penalty < b.penalty;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<Node> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].univ >> v[i].name >> v[i].solved >> v[i].penalty;
	}

	sort(v.begin(), v.end(), cmp);

	unordered_map<string, bool> map;
	vector<string > ans;

	for (auto& t : v) {
		if (!map[t.univ]) {
			map[t.univ] = true;
			ans.push_back(t.name);

			if (ans.size() == k) {
				break;
			}
		}
	}

	for (auto& name : ans) {
		cout << name << "\n";
	}
}