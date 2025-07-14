#pragma once
#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    int start = h1 * 3600 + m1 * 60 + s1;
    int endi = h2 * 3600 + m2 * 60 + s2;

    if (start == 0 || start == 12 * 3600) {
        answer++;
    }

    while (start < endi) {
        double hA = fmod((double)start / 120.0, 360.0);
        double mA = fmod((double)start / 10.0, 360.0);
        double sA = fmod((double)start * 6.0, 360.0);

        double hnA = fmod((double)(start + 1) / 120.0, 360.0);
        double mnA = fmod((double)(start + 1) / 10.0, 360.0);
        double snA = fmod((double)(start + 1) * 6.0, 360.0);

        if (hnA == 0) hnA = 360;
        if (mnA == 0) mnA = 360;
        if (snA == 0) snA = 360;

        if (sA < hA && snA >= hnA)
            answer++;
        if (sA < mA && snA >= mnA)
            answer++;
        if (fabs(snA - hnA) < 1e-8 && fabs(hnA - mnA) < 1e-8)
            answer--;

        start++;
    }

    return answer;
}