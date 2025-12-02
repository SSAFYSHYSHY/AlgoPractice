#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

struct Node {
	int id, time, prior;
};

struct cmp {
	bool operator()(const Node& a, const Node& b) const {
		if (a.prior == b.prior) return a.id > b.id;
		return a.prior < b.prior;
	}
};

int main() {
	int t, n;
	cin >> t >> n;

	priority_queue<Node, vector<Node>, cmp> pq;
	int id, time, prior;

	while (n-- > 0) {
		cin >> id >> time >> prior;

		pq.push({ id, time, prior });
	}

	stringstream ss;

	while (t-- > 0 && !pq.empty()) {
		Node node = pq.top();
		pq.pop();

		ss << node.id << "\n";

		node.prior--;
		node.time = max(node.time - 1, 0);

		if (node.time > 0) {
			pq.push(node);
		}
	}

	cout << ss.str();
}
