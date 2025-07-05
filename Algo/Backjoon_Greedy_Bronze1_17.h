#pragma once
#include <iostream>

using namespace std;

int A, B, C, S, V, L;

int main() {

    cin >> A >> B >> C >> S >> V >> L;

    int exp = L * 100, time = 0;
    const int EXP = 25000;

    while (exp < EXP) {
        if (V) {
            int gain = C * 30;
            if (exp + gain > EXP)
                time += (EXP - exp + C - 1) / C;
            else
                time += 30;
            exp += gain;
            V--;
        }
        else if (S) {
            int gain = B * 30;
            if (exp + gain > EXP)
                time += (EXP - exp + B - 1) / B;
            else
                time += 30;
            exp += gain;
            S--;
        }
        else {
            exp += A;
            time++;
        }
    }

    cout << time;
    return 0;
}
