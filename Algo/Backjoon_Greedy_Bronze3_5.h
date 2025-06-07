#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
double maxi = 0, mini = 0;

int main() {
    cout << fixed;
    cout.precision(4);

    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    int remain = n - m;
    double sum1 = sum;

    // �ּ� ����: �������� ��� -3�� ��
    sum1 += -3 * remain;

    // �ִ� ����: �������� ��� +3�� ��
    sum += 3 * remain;

    mini = sum1 / n;
    maxi = static_cast<double>(sum) / n;

    cout << mini << " " << maxi;
}
