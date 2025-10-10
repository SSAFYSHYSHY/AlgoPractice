#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int n, m;

struct Trie {
	bool flag;
	map<char, Trie*> children;

	Trie() : flag(false) {};
};

void Insert(Trie* root, const string& word) {
	Trie* node = root;

	for (char c : word) {
		if (!node->children[c]) {
			node->children[c] = new Trie();
		}
		node = node->children[c];
	}

	node->flag = true;
}

bool Find(Trie* root, const string& word) {
	Trie* node = root;

	for (char c : word) {
		if (!node->children[c]) {
			return false;
		}
		node = node->children[c];
	}

	return node->flag;

}

int main() {
	cin >> n >> m;

	Trie* trie = new Trie();

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		Insert(trie, s);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (Find(trie, s)) {
			ans++;
		}
	}

	cout << ans;
}