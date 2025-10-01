#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dict;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx = 27;

    // 1. A~Z 사전 초기화
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        string s(1, c);
        dict[s] = i + 1;
    }

    // 2. 메시지 압축
    for (int i = 0; i < msg.size();) {
        string w(1, msg[i]);
        int j = i + 1;

        // 사전에 있는 가장 긴 문자열 찾기
        while (j <= msg.size() && dict.find(msg.substr(i, j - i)) != dict.end()) {
            w = msg.substr(i, j - i);
            j++;
        }

        // 출력
        answer.push_back(dict[w]);

        // 사전에 새 단어 추가
        if (j <= msg.size()) {
            dict[msg.substr(i, j - i)] = idx++;
        }

        // 포인터 이동
        i += w.size();
    }

    return answer;
}