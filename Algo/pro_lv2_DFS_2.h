#pragma once
#include <string>
#include <vector>

using namespace std;

string s = "AEIOU";
int answer = -1, cnt = 0;

void DFS(string now, string ans) {
    if (cnt == answer) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        now += s[i];
        cnt++;

        if (now == ans) {
            answer = cnt;
            return;
        }

        if (now.size() < 5) {
            DFS(now, ans);
        }
        now.pop_back();
    }
}

int solution(string word) {

    DFS("", word);

    return answer;
}