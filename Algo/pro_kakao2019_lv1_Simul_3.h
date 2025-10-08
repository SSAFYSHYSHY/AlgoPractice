#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct File {
    string head, number, tail;
    int idx; // 입력 순서 (안정 정렬용)
};

bool cmp(const File& a, const File& b) {
    string A = a.head, B = b.head;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    transform(B.begin(), B.end(), B.begin(), ::tolower);

    if (A != B) return A < B; // HEAD 사전순 (대소문자 무시)
    int numA = stoi(a.number);
    int numB = stoi(b.number);
    if (numA != numB) return numA < numB; // NUMBER 정렬
    return a.idx < b.idx; // 입력 순서 유지
}

vector<string> solution(vector<string> files) {
    vector<File> v;

    for (int i = 0; i < files.size(); i++) {
        string s = files[i];
        string head, num, tail;
        int j = 0, n = s.size();

        // 1️⃣ HEAD
        while (j < n && !isdigit(s[j])) head += s[j++];

        // 2️⃣ NUMBER (1~5자리)
        int cnt = 0;
        while (j < n && isdigit(s[j]) && cnt < 5) {
            num += s[j++];
            cnt++;
        }

        // 3️⃣ TAIL (남은 부분)
        tail = s.substr(j);

        v.push_back({ head, num, tail, i });
    }

    stable_sort(v.begin(), v.end(), cmp);

    vector<string> answer;
    for (auto& f : v)
        answer.push_back(f.head + f.number + f.tail);

    return answer;
}
