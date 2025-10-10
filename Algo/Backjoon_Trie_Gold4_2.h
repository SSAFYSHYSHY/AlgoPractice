#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int N, M;

struct Trie {
	map<string, Trie*> children;
};

void Insert(Trie* root, const string& word, int& newcnt) {
	stringstream ss(word);
	string dir;

	getline(ss, dir, '/');
	Trie* node = root;

	while (getline(ss, dir, '/')) {
		if (!node->children.count(dir)) {
			node->children[dir] = new Trie();
			newcnt++;
		}
		node = node->children[dir];
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;

		Trie* root = new Trie();

		//이미 존재하는 디렉터의 삽입.
		for (int i = 0; i < N; i++) {
			string path;
			cin >> path;

			int dummy = 0;
			Insert(root, path, dummy);
		}

		int cnt = 0;
		for (int i = 0; i < M; i++) {
			string path;
			cin >> path;

			Insert(root, path, cnt);
		}

		cout << "Case #" << tc << ": " << cnt << "\n";
	}
}