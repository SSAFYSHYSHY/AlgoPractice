#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

bool IsPrime(long long num) {
    if (num <= 1) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

string Calc(int n, int k) {
    string temp;
    while (n > 0) {
        temp = to_string(n % k) + temp;
        n /= k;
    }

    return temp;
}

int solution(int n, int k) {
    int answer = -1;
    string s = Calc(n, k);

    vector<long long> v;
    string temp;
    stringstream ss(s);

    while (getline(ss, temp, '0')) {
        if (!temp.empty()) {
            v.push_back(stoll(temp));
        }
    }

    int cnt = 0;
    for (long long i = 0; i < v.size(); i++) {
        if (IsPrime(v[i])) {
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}