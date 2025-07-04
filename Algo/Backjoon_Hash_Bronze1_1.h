#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int n;
unordered_set<string> word_set;

int main() {
    cin >> n;
    string answer = "";

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        // �̹� ������ ���ڿ��� ���տ� �ְų�, �ڱ� �ڽ��� �Ӹ������ ���
        if (word_set.count(rev) || s == rev) {
            answer = s;
        }

        word_set.insert(s);
    }

    if (!answer.empty()) {
        cout << answer.length() << " " << answer[answer.length() / 2] << "\n";
    }
}
