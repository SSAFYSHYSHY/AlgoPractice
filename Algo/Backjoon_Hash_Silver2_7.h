#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string s[200001]; // �ܾ ������ �迭
map<pair<string, string>, string> mp; // ù, ������ ���ڿ� ���ĵ� ���ڿ��� Ű�� �ϴ� ��

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // ������ �ܾ��� ����
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string k = s; // �ܾ� ���纻
        string se = "";
        se += s[0]; // ù ���� ����
        se += s[s.size() - 1]; // ������ ���� ����

        sort(k.begin(), k.end()); // �ܾ� ����
        mp[{se, k}] = s; // (ù����+����������, ���ĵ� ���ڿ�)�� Ű�� ���� �ܾ� ����
    }

    int m; // �׽�Ʈ �ܾ� ����
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        string k = s; // �ܾ� ���纻
        string se = "";
        se += s[0]; // ù ����
        se += s[s.size() - 1]; // ������ ����

        sort(k.begin(), k.end()); // �ܾ� ����
        cout << mp[{se, k}] << ' '; // ���� �ܾ� ���
    }

    return 0;
}