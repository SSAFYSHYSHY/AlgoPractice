#pragma once
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll A, B, C, D, K;
    cin >> A >> B >> C >> D >> K;

    // ������ �ִ� �� �� ��� (�־��� ���)
    ll End = (A + C + D - 1) / D;

    ll S = 1;
    ll E = End;
    ll Catch = End + 1;
    ll Arrive = End + 1;

    while (S <= E) {
        ll T = (S + E) / 2;

        // ���� ���� ���Ұ� 0 ���Ϸ� �������ٸ�, �� �̻� ��� �Ұ�
        ll damage = B - K * (T - 1);
        if (damage <= 0) {
            E = T - 1;
            continue;
        }

        // ���� ���� ���: T * (2B - K(T-1)) / 2
        // ���� �� �ִ� ���� ����(Toca)
        ll first_term = 2 * B;
        ll second_term = K * (T - 1);
        ll total = T * (first_term - second_term); // ����
        ll Toca = A - total / 2;

        // �ð� T�� ������ ������ ü��
        ll Doldol = A + C - T * D;

        if (Toca <= 0) {
            // ������ ���� (��� ����)
            Arrive = min(Arrive, T);
            E = T - 1;
        }
        else {
            if (Toca >= Doldol) {
                // ���� ������ ���� �� ����
                Catch = min(Catch, T);
            }
            S = T + 1;
        }
    }

    if (Arrive < Catch) {
        cout << Arrive;
    }
    else {
        cout << -1;
    }
}
