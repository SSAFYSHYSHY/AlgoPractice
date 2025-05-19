#pragma once
#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 100

using namespace std;

int N, M, K;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
vector<int> V;

void Input() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
}

void Print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
}

void Copy_MAP(int A[][MAX], int B[][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = B[i][j];
        }
    }
}

// 상하 반전
void Cmd_One() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C_MAP[N - i - 1][j] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

// 좌우 반전
void Cmd_Two() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C_MAP[i][M - j - 1] = MAP[i][j];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

// 오른쪽 90도 회전
void Cmd_Three() {
    int temp = N;
    swap(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C_MAP[i][j] = MAP[temp - 1 - j][i];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

// 왼쪽 90도 회전
void Cmd_Four() {
    int temp = M;
    swap(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C_MAP[i][j] = MAP[j][temp - 1 - i];
        }
    }
    Copy_MAP(MAP, C_MAP);
}

// 4사분면을 시계 방향으로 회전
void Cmd_Five() {
    int halfN = N / 2;
    int halfM = M / 2;

    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfM; j++) {
            C_MAP[i][j + halfM] = MAP[i][j]; // 1 -> 2
        }
    }

    for (int i = 0; i < halfN; i++) {
        for (int j = halfM; j < M; j++) {
            C_MAP[i + halfN][j] = MAP[i][j]; // 2 -> 3
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = halfM; j < M; j++) {
            C_MAP[i][j - halfM] = MAP[i][j]; // 3 -> 4
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = 0; j < halfM; j++) {
            C_MAP[i - halfN][j] = MAP[i][j]; // 4 -> 1
        }
    }

    Copy_MAP(MAP, C_MAP);
}

// 4사분면을 반시계 방향으로 회전
void Cmd_Six() {
    int halfN = N / 2;
    int halfM = M / 2;

    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfM; j++) {
            C_MAP[i + halfN][j] = MAP[i][j]; // 1 -> 4
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = 0; j < halfM; j++) {
            C_MAP[i][j + halfM] = MAP[i][j]; // 4 -> 3
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = halfM; j < M; j++) {
            C_MAP[i - halfN][j] = MAP[i][j]; // 3 -> 2
        }
    }

    for (int i = 0; i < halfN; i++) {
        for (int j = halfM; j < M; j++) {
            C_MAP[i][j - halfM] = MAP[i][j]; // 2 -> 1
        }
    }

    Copy_MAP(MAP, C_MAP);
}

void Solution() {
    for (int cmd : V) {
        if (cmd == 1) Cmd_One();
        else if (cmd == 2) Cmd_Two();
        else if (cmd == 3) Cmd_Three();
        else if (cmd == 4) Cmd_Four();
        else if (cmd == 5) Cmd_Five();
        else if (cmd == 6) Cmd_Six();
    }

    Print();
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
