#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int t;

struct Trie {
	bool flag;
	map<char, Trie*> children;
	Trie() : flag(false) {}
};

void Insert(Trie* node, const string& word) {
	for (char c : word) {
		if (!node->children[c]) {
			node->children[c] = new Trie();
		}
		node = node->children[c];
	}
	node->flag = true;
}

// word�� Ʈ���� ���� � �ܾ��� ���λ����� Ȯ��
bool Start(Trie* node, const string& word) {
	for (char c : word) {
		if (!node->children[c]) return false;
		node = node->children[c];
		// node->flag�� true��� ���ݱ����� prefix�� ���� �ܾ���
		if (node->flag && c != word.back()) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;

	while (t--) {
		Trie* trie = new Trie();
		int n;
		cin >> n;
		vector<string> v(n);

		for (int i = 0; i < n; i++) cin >> v[i];

		sort(v.begin(), v.end());
		bool flag = true;

		for (int i = 0; i < n; i++) {
			if (Start(trie, v[i])) {
				flag = false;
				break;
			}
			Insert(trie, v[i]);
		}

		cout << (flag ? "YES\n" : "NO\n");
	}
}
