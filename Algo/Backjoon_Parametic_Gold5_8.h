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

    // 가능한 최대 일 수 계산 (최악의 경우)
    ll End = (A + C + D - 1) / D;

    ll S = 1;
    ll E = End;
    ll Catch = End + 1;
    ll Arrive = End + 1;

    while (S <= E) {
        ll T = (S + E) / 2;

        // 만약 방어력 감소가 0 이하로 떨어졌다면, 더 이상 계산 불가
        ll damage = B - K * (T - 1);
        if (damage <= 0) {
            E = T - 1;
            continue;
        }

        // 누적 피해 계산: T * (2B - K(T-1)) / 2
        // 피할 수 있는 누적 피해(Toca)
        ll first_term = 2 * B;
        ll second_term = K * (T - 1);
        ll total = T * (first_term - second_term); // 분자
        ll Toca = A - total / 2;

        // 시간 T에 도달한 돌돌이 체력
        ll Doldol = A + C - T * D;

        if (Toca <= 0) {
            // 무조건 도착 (방어 무시)
            Arrive = min(Arrive, T);
            E = T - 1;
        }
        else {
            if (Toca >= Doldol) {
                // 도달 시점에 잡을 수 있음
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
