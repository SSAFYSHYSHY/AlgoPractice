#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	string name;
	int agediff;
};

void BFS(map<string, vector<Node>>& tree, map<string, int>& age) {
	queue<pair<string, int>> q;
	q.push({ "Ted", 100 });
	age["Ted"] = 100;

	while (!q.empty()) {
		string cname = q.front().first;
		int cage = q.front().second;
		q.pop();

		for (auto& child : tree[cname]) {
			int childage = cage - child.agediff;
			age[child.name] = childage;
			q.push({ child.name, childage });  // °íÄ§
		}
	}
}

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int x;
		cin >> x;

		map<string, vector<Node>> tree;
		map<string, int> age;
		vector<string> v;

		for (int i = 0; i < x; i++) {
			string parent, child;
			int agediff;
			cin >> parent >> child >> agediff;

			tree[parent].push_back({ child, agediff });
			v.push_back(child);
		}

		BFS(tree, age);

		vector<pair<string, int>> ans;
		for (const string& name : v) {
			ans.push_back({ name, age[name] });
		}

		sort(ans.begin(), ans.end(), cmp);

		cout << "DATASET " << t << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
}
