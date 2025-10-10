#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    map<string, Trie*> children;  // key: 단어, value: 하위 Trie 노드
};

void Insert(Trie* node, const vector<string>& words) {
    for (const string& w : words) {
        // 현재 단어(w)에 해당하는 자식 노드가 없으면 새로 생성
        if (node->children.find(w) == node->children.end()) {
            node->children[w] = new Trie();
        }
        // 다음 깊이로 이동
        node = node->children[w];
    }
}

// depth를 이용해 들여쓰기 출력
void Print(Trie* node, int depth) {
    // map은 자동으로 key 기준 오름차순 정렬됨
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        string key = it->first;          // 현재 층의 단어
        Trie* child = it->second;        // 하위 Trie 노드

        // depth만큼 들여쓰기 ("--" 사용)
        for (int i = 0; i < depth; i++) cout << "--";
        cout << key << "\n";

        // 재귀적으로 하위 노드 탐색
        Print(child, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Trie* root = new Trie();

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<string> words(k);
        for (int j = 0; j < k; j++) cin >> words[j];

        Insert(root, words);
    }

    Print(root, 0);
    return 0;
}
