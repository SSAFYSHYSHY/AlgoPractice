#pragma once
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int Calc(const vector<int>& arr) {
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        ans = gcd(ans, arr[i]);
    }
    return ans;
}

bool Flag(int val, const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % val == 0) return false;
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcda = Calc(arrayA);
    int gcdb = Calc(arrayB);

    int answer = 0;

    if (Flag(gcda, arrayB)) {
        answer = max(answer, gcda);
    }
    if (Flag(gcdb, arrayA)) {
        answer = max(answer, gcdb);
    }

    return answer;
}