#pragma once
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    for (int i = s.length() - 1; i >= 0; i--) {
        char a = s[i];
        bool flag = false;

        for (int j = i - 1; j >= 0; j--) {
            if (a == s[j]) {
                flag = true;
                int num = i - j;
                answer.push_back(num);
                break;
            }
        }

        if (!flag) {
            answer.push_back(-1);
        }
    }

    vector<int> ans;
    for (int i = answer.size() - 1; i >= 0; i--) {
        ans.push_back(answer[i]);
    }

    return ans;
}