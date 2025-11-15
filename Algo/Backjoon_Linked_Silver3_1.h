#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node* prev, * next;
};

int main() {
	int n, k, a, b, c;
	cin >> n >> k;

	Node* nodes = (Node*)malloc(sizeof(Node) * (n + 1));

	for (int i = 0; i <= n; i++) {
		nodes[i].data = i;
		if (i > 0) nodes[i].prev = &nodes[i - 1];
		else nodes[i].prev = NULL;
		if (i < n) nodes[i].next = &nodes[i + 1];
		else nodes[i].next = NULL;
	}

	for (int i = 0; i < k; i++) {}
}