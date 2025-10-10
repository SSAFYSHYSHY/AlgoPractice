#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    map<string, Trie*> children;  // key: �ܾ�, value: ���� Trie ���
};

void Insert(Trie* node, const vector<string>& words) {
    for (const string& w : words) {
        // ���� �ܾ�(w)�� �ش��ϴ� �ڽ� ��尡 ������ ���� ����
        if (node->children.find(w) == node->children.end()) {
            node->children[w] = new Trie();
        }
        // ���� ���̷� �̵�
        node = node->children[w];
    }
}

// depth�� �̿��� �鿩���� ���
void Print(Trie* node, int depth) {
    // map�� �ڵ����� key ���� �������� ���ĵ�
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        string key = it->first;          // ���� ���� �ܾ�
        Trie* child = it->second;        // ���� Trie ���

        // depth��ŭ �鿩���� ("--" ���)
        for (int i = 0; i < depth; i++) cout << "--";
        cout << key << "\n";

        // ��������� ���� ��� Ž��
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
