#pragma once
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;

vector<int> wants[MAX]; // �л� i�� ���ϴ� å ����Ʈ
int match[MAX];         // å j�� ��Ī�� �л� ��ȣ
bool visited[MAX];      // �湮 üũ (å ����)

bool dfs(int student) {
    for (int book : wants[student]) {
        // �̹� ������ �л��� ���� ������.
        if (visited[book]) continue;

        visited[book] = true;

        // �� å�� ���� �� ��ų�, ���� �л��� �ٸ� å ���� �� �ִ� ���
        if (match[book] == 0 || dfs(match[book])) {
            match[book] = student;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        // �ʱ�ȭ
        for (int i = 1; i <= M; ++i) wants[i].clear();
        memset(match, 0, sizeof(match));

        for (int i = 1; i <= M; ++i) {
            int a, b;
            cin >> a >> b;
            for (int j = a; j <= b; ++j) {
                wants[i].push_back(j);
            }
        }

        int answer = 0;
        for (int student = 1; student <= M; ++student) {
            memset(visited, false, sizeof(visited));
            if (dfs(student)) answer++;
        }

        cout << answer << '\n';
    }

    return 0;
}