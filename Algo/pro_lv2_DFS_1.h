#pragma once
#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[9] = { false, };

void DFS(int now, int k, const vector<vector<int>>& dungeons) {
    if (now > answer) {
        answer = now;
    }

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            DFS(now + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    //int answer = -1;

    DFS(0, k, dungeons);

    return answer;
}