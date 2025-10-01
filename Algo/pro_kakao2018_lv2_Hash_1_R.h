#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dict;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx = 27;

    // 1. A~Z ���� �ʱ�ȭ
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        string s(1, c);
        dict[s] = i + 1;
    }

    // 2. �޽��� ����
    for (int i = 0; i < msg.size();) {
        string w(1, msg[i]);
        int j = i + 1;

        // ������ �ִ� ���� �� ���ڿ� ã��
        while (j <= msg.size() && dict.find(msg.substr(i, j - i)) != dict.end()) {
            w = msg.substr(i, j - i);
            j++;
        }

        // ���
        answer.push_back(dict[w]);

        // ������ �� �ܾ� �߰�
        if (j <= msg.size()) {
            dict[msg.substr(i, j - i)] = idx++;
        }

        // ������ �̵�
        i += w.size();
    }

    return answer;
}