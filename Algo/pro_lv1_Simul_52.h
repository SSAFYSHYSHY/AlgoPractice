#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i = 0;
    int len = section.size();

    while (i < len) {
        int start = section[i];
        answer++;

        while (i < len && section[i] < start + m) {
            i++;
        }
    }


    return answer;
}