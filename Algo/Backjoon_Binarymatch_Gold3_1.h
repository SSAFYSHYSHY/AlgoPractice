#pragma once
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;

vector<int> wants[MAX]; // 학생 i가 원하는 책 리스트
int match[MAX];         // 책 j가 매칭된 학생 번호
bool visited[MAX];      // 방문 체크 (책 기준)

bool dfs(int student) {
    for (int book : wants[student]) {
        // 이미 최적의 학생이 독점 했으면.
        if (visited[book]) continue;

        visited[book] = true;

        // 그 책이 아직 안 줬거나, 기존 학생이 다른 책 받을 수 있는 경우
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

        // 초기화
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