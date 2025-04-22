#pragma once
#include <string>
#include <vector>

using namespace std;

string ans = "0123456789ABCDEF";

string Calc(int n, int num) {
    string temp;

    if (num == 0) return "0";
    while (num) {
        temp = ans[num % n] + temp;
        num /= n;
    }

    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s;
    int num = 0;

    while (s.size() <= t * m) {
        s += Calc(n, num++);
    }

    num = p - 1;
    while (answer.size() < t) {
        answer += s[num];
        num += m;
    }

    return answer;

}