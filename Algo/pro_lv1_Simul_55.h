#pragma once
#include <string>
#include <vector>

using namespace std;

string Calc(int num, int n) {
    string s;

    while (num > 0) {
        if (num % 2 == 1) {
            s = "#" + s;
        }
        else {
            s = " " + s;
        }
        num /= 2;
    }
    while (s.length() < n) {
        s = " " + s;
    }

    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < arr1.size(); i++) {
        int num = arr1[i] | arr2[i];

        string s = Calc(num, n);
        answer.push_back(s);
    }

    return answer;
}