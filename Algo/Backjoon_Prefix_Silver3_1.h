#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // �Ƹ��ٿ� �� ����: pair[a][b] == true �� (a, b)�� �Ƹ��ٿ� ��
    bool pair[26][26] = { false };

    for (int i = 0; i < k; i++) {
        char a, b;
        cin >> a >> b;
        pair[a - 'a'][b - 'a'] = true;
    }

    // ������: �� ���� c�� ����, ���ݱ��� ������ Ƚ�� cnt[c]
    vector<long long> count(26, 0);

    long long result = 0;

    for (char ch : s) {
        int current = ch - 'a';

        // ���ݱ��� ������ a ��, (a, current)�� �Ƹ��ٿ� ���� ��� ����ŭ ����
        for (int prev = 0; prev < 26; prev++) {
            if (pair[prev][current]) {
                result += count[prev];
            }
        }

        // ���� ���� ���� Ƚ�� ����
        count[current]++;
    }

    cout << result << endl;
    return 0;
}
