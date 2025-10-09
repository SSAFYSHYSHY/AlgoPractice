#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, t;
char arr[4][4];
bool visited[4][4];

unordered_set<string> found;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void Insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool Find(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->isEnd;
    }

    bool StartsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return true;
    }
};

Trie trie;

bool InRange(int x, int y) {
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void Back(int x, int y, vector<char>& path) {
    string s(path.begin(), path.end());

    if (!trie.StartsWith(s)) return;
    if (s.length() >= 3 && trie.Find(s)) found.insert(s);

    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!InRange(nx, ny) || visited[nx][ny]) continue;

        visited[nx][ny] = true;
        path.push_back(arr[nx][ny]);
        Back(nx, ny, path);
        path.pop_back();
        visited[nx][ny] = false;
    }
}

int GetScore(const string& s) {
    int len = s.length();
    if (len == 3 || len == 4) return 1;
    if (len == 5) return 2;
    if (len == 6) return 3;
    if (len == 7) return 5;
    if (len >= 8) return 11;
    return 0;
}

struct Node {
    int len;
    string s;
};

bool cmp(Node& a, Node& b) {
    if (a.len == b.len) return a.s < b.s;
    return a.len > b.len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.Insert(s);
    }

    cin.ignore(); // 사전 끝난 뒤 개행 제거
    cin.ignore(); // 빈 줄 제거
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        found.clear();

        for (int i = 0; i < 4; i++) {
            cin >> s;
            for (int j = 0; j < 4; j++) arr[i][j] = s[j];
        }

        // 각 보드 탐색
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                memset(visited, false, sizeof(visited));
                vector<char> path;
                visited[i][j] = true;
                path.push_back(arr[i][j]);
                Back(i, j, path);
            }
        }

        int totalScore = 0;
        vector<Node> list;
        for (auto& w : found) {
            totalScore += GetScore(w);
            list.push_back({ (int)w.size(), w });
        }

        sort(list.begin(), list.end(), cmp);
        string bestWord = list.empty() ? "" : list[0].s;

        cout << totalScore << " " << bestWord << " " << (int)found.size() << "\n";

        if (tc != t - 1) cin.ignore();
    }
}
