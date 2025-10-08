#pragma once
#include <string>
#include <vector>

using namespace std;

struct Trie {
    Trie* next[26];
    int cnt;

    Trie() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
            cnt = 0;
        }
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }

    void insert(const string& s) {
        Trie* node = this;

        for (char c : s) {
            int idx = c - 'a';

            if (!node->next[idx]) node->next[idx] = new Trie();
            node = node->next[idx];
            node->cnt++;
        }
    }

    int find(const string& s) {
        Trie* node = this;

        int depth = 0;
        for (char c : s) {
            int idx = c - 'a';
            node = node->next[idx];
            depth++;

            if (node->cnt == 1) break;
        }

        return depth;
    }
};

int solution(vector<string> words) {
    Trie* root = new Trie();

    for (auto& w : words) root->insert(w);

    int ans = 0;
    for (auto& w : words) ans += root->find(w);

    delete root;
    return ans;
}