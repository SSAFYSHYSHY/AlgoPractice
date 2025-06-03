#pragma once
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;

    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        bool flag = false;

        for (int j = 0; j < numbers.size(); j++) {

            if (i == numbers[j]) {
                flag = true;
            }
        }

        if (!flag) {
            sum += i;
        }
    }

    answer = sum;
    return answer;
}