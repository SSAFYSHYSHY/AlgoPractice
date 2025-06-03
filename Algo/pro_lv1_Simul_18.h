#pragma once
int solution(int num) {
    long long answer = num;

    for (int i = 0; i < 500; i++) {
        if (answer == 1) {
            return i;
        }

        if (answer % 2 == 0) {
            answer /= 2;
        }
        else {
            answer = answer * 3 + 1;
        }
    }

    return -1;
}
