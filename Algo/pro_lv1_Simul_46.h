#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int one[] = { 1,2,3,4,5 };
int two[] = { 2,1,2,3,2,4,2,5 };
int three[] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    //각 배열 길이들.
    int a = 5, b = 8, c = 10;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (one[i % a] == answers[i]) {
            cnt1++;
        }
        if (two[i % b] == answers[i]) {
            cnt2++;
        }
        if (three[i % c] == answers[i]) {
            cnt3++;
        }
    }

    int maxscore = max({ cnt1, cnt2, cnt3 });

    if (cnt1 == maxscore) answer.push_back(1);
    if (cnt2 == maxscore) answer.push_back(2);
    if (cnt3 == maxscore) answer.push_back(3);
    return answer;
}