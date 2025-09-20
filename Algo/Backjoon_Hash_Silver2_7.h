#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string s[200001]; // 단어를 저장할 배열
map<pair<string, string>, string> mp; // 첫, 마지막 글자와 정렬된 문자열을 키로 하는 맵

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 저장할 단어의 개수
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string k = s; // 단어 복사본
        string se = "";
        se += s[0]; // 첫 글자 저장
        se += s[s.size() - 1]; // 마지막 글자 저장

        sort(k.begin(), k.end()); // 단어 정렬
        mp[{se, k}] = s; // (첫글자+마지막글자, 정렬된 문자열)를 키로 원래 단어 저장
    }

    int m; // 테스트 단어 개수
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        string k = s; // 단어 복사본
        string se = "";
        se += s[0]; // 첫 글자
        se += s[s.size() - 1]; // 마지막 글자

        sort(k.begin(), k.end()); // 단어 정렬
        cout << mp[{se, k}] << ' '; // 원래 단어 출력
    }

    return 0;
}