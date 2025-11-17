#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int s, b;
struct Node {
	int id;
	Node* prev, * next;
	Node(int i) : id(i), prev(nullptr), next(nullptr) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	while (cin >> s >> b) {
		if (s == 0 && b == 0) break;

		vector<Node*> v(s + 2, nullptr);

		v[0] = new Node(0);
		v[s + 1] = new Node(s + 1);

		for (int i = 1; i <= s; i++) {
			v[i] = new Node(i);
		}

		//¾ç¿· ¿¬°á
		for (int i = 1; i <= s; i++) {
			v[i]->prev = v[i - 1];
			v[i]->next = v[i + 1];
		}

		int l, r;
		while (b--) {
			cin >> l >> r;

			Node* left = v[l]->prev;
			Node* right = v[r]->next;

			if (left->id == 0) std::cout << "* ";
			else std::cout << left->id << " ";

			if (right->id == s + 1) std::cout << "*\n";
			else std::cout << right->id << "\n";

			left->next = right;
			right->prev = left;
		}

		std::cout << "-\n";
	}
}