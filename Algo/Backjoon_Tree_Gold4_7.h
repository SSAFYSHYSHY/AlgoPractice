#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
	bool isEnd;
	TrieNode* children[11];

	TrieNode() {
		isEnd = false;
		fill(children, children + 11, nullptr);
	}
};

class Trie {
public:
	TrieNode* root;
	Trie() { root = new TrieNode(); }

	bool insert(const string& word) {
		TrieNode* curr = root;

		for (char ch : word) {
			int idx = ch - '0';

			if (curr->isEnd) return false;

			if (!curr->children[idx]) {
				curr->children[idx] = new TrieNode();
			}

			curr = curr->children[idx];
		}


		for (int i = 0; i < 11; i++) {
			if (curr->children[i]) {
				return false;
			}
		}

		curr->isEnd = true;
		return true;
	}
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		Trie trie;
		bool flag = true;

		for (string& num : v) {
			if (!trie.insert(num)) {
				flag = false;
				break;
			}
		}

		cout << (flag ? "YES" : "NO") << "\n";
	}
}