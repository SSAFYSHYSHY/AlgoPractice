#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXI 100001

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int n) : data(n), next(nullptr) {}
};

int main() {
	Node* head = new Node(2);
	Node* cur = head;

	for (int i = 3; i <= MAXI; i++) {
		cur->next = new Node(i);
		cur = cur->next;
	}

	vector<int> v;
	Node* p = head;

	while (v.size() < 3000 && p != nullptr) {
		v.push_back(p->data);

		int step = p->data;
		Node* prev = p;
		Node* node = p->next;

		int cnt = 1;
		while (node != nullptr) {
			if (cnt % step == 0) {
				prev->next = node->next;
				delete node;
				node = prev->next;
			}
			else {
				prev = node;
				node = node->next;
			}
			cnt++;
		}

		p = p->next;
	}

	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;

		cout << v[n - 1] << "\n";
	}
}