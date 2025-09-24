#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> v;

int solution(string dartResult) {
    int answer = 0;

    int op = 0, num = 0;
    string s;

    for (int i = 0; i < dartResult.size(); i++) {
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            s += dartResult[i];
        }

        if (dartResult[i] == 'S') { num = stoi(s); num = pow(num, 1); v.push_back(num); s = ""; }
        else if (dartResult[i] == 'D') { num = stoi(s); num = pow(num, 2); v.push_back(num); s = ""; }
        else if (dartResult[i] == 'T') { num = stoi(s); num = pow(num, 3); v.push_back(num); s = ""; }


        if (dartResult[i] == '*') {
            int len = v.size();
            v[len - 1] = v[len - 1] * 2;
            v[len - 2] = v[len - 2] * 2;
        }
        else if (dartResult[i] == '#') {
            int len = v.size();
            v[len - 1] = v[len - 1] * -1;
        }

    }

    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }

    return answer;
}