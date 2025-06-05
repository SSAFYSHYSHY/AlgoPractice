#pragma once
#include <string>
#include <vector>

using namespace std;

int Calc(int num) {
    int cnt = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            cnt++;

            //Á¦°ö¼ö Ã³¸®.
            if (i != num / i)
                cnt++;
        }
    }

    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> v;
    for (int i = 1; i <= number; i++) {
        int num = Calc(i);
        v.push_back(num);
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= limit) {
            answer += v[i];
        }
        else {
            answer += power;
        }
    }

    return answer;
}