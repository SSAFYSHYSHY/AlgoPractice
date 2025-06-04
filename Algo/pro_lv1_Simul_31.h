#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int gcd2 = gcd(n, m);
    int lcm = (n * m) / gcd2;

    answer.push_back(gcd2);
    answer.push_back(lcm);

    return answer;
}