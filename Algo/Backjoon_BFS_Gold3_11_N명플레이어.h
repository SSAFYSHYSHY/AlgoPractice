#pragma once

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_set>
using namespace std;

// 4���� + �밢�� 8���� �̵� ����
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

struct State {
    pair<int, int> A;
    pair<int, int> B;

    bool operator==(const State& other) const {
        return A == other.A && B == other.B;
    }
};

struct StateHash {
    size_t operator()(const State& s) const {
        return hash<int>()(s.A.first * 31 + s.A.second) ^ hash<int>()(s.B.first * 31 + s.B.second);
    }
};

int N, M;
char board[21][21];
pair<int, int> startA, startB, goalA, goalB;

bool InRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int BFS() {
    queue<pair<State, int>> q; // ���� + ��
    unordered_set<State, StateHash> visited;

    State start{ startA, startB };
    q.push({ start, 0 });
    visited.insert(start);

    while (!q.empty()) {
        State cur = q.front().first; 
        int dist = q.front().second;
        q.pop();

        // ��ǥ ���� Ȯ�� (�ڸ� �ٲٱ�)
        if (cur.A == goalB && cur.B == goalA)
            return dist;

        // 8���� �̵� ����
        for (int da = 0; da < 8; da++) {
            int nax = cur.A.first + dx[da];
            int nay = cur.A.second + dx[da]; // ����: dy ���
            if (!InRange(nax, nay) || board[nax][nay] == 'X') { nax = cur.A.first; nay = cur.A.second; } // ���̸� �̵�X

            for (int db = 0; db < 8; db++) {
                int nbx = cur.B.first + dx[db];
                int nby = cur.B.second + dy[db];
                if (!InRange(nbx, nby) || board[nbx][nby] == 'X') { nbx = cur.B.first; nby = cur.B.second; }

                // ���� ĭ ���� + ���� ����
                if (nax == nbx && nay == nby) continue;
                if (nax == cur.B.first && nay == cur.B.second && nbx == cur.A.first && nby == cur.A.second) continue;

                State next{ {nax,nay},{nbx,nby} };
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({ next, dist + 1 });
                }
            }
        }
    }

    return -1; // �Ұ���
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'A') startA = { i,j }, goalA = { i,j }, board[i][j] = '.';
            if (board[i][j] == 'B') startB = { i,j }, goalB = { i,j }, board[i][j] = '.';
        }
    }

    cout << BFS() << "\n";
}
