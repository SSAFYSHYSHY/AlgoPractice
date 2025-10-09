#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
int arr[55];
vector<int> truth;
vector<vector<int>> party;

int Find(int x) {
    if (arr[x] == x) return x;
    return arr[x] = Find(arr[x]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    arr[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int t;
    cin >> t; // ���� �ƴ� ��� ��
    truth.resize(t);
    for (int i = 0; i < t; i++)
        cin >> truth[i];

    // ��Ƽ ���� �Է�
    party.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        party[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> party[i][j];
    }

    // �ʱ�ȭ
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    // ���� ��Ƽ ����鳢�� Union
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < (int)party[i].size(); j++)
            Merge(party[i][0], party[i][j]);
    }

    // ���� �ƴ� ������� ��Ʈ�� ����
    set<int> truthRoot;
    for (int person : truth)
        truthRoot.insert(Find(person));

    int result = 0;

    // �� ��Ƽ�� ���� ��Ʈ�� ����Ǿ� �ִ��� Ȯ��
    for (int i = 0; i < m; i++) {
        bool canLie = true;
        for (int person : party[i]) {
            if (truthRoot.count(Find(person))) {
                canLie = false;
                break;
            }
        }
        if (canLie) result++;
    }

    cout << result;
}
