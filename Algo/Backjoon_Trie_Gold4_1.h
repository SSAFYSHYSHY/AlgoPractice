#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool exists(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> words;
    Trie trie;
    string s;

    // 모든 단어 입력
    while (cin >> s) {
        words.push_back(s);
        trie.insert(s);
    }

    vector<string> compounds;

    // 합성어 판단
    for (auto& word : words) {
        int len = word.size();
        for (int i = 1; i < len; i++) {
            string pre = word.substr(0, i);
            string suf = word.substr(i);
            if (trie.exists(pre) && trie.exists(suf)) {
                compounds.push_back(word);
                break;
            }
        }
    }

    // 사전순 출력
    sort(compounds.begin(), compounds.end());
    for (auto& w : compounds) cout << w << "\n";

    return 0;
}
