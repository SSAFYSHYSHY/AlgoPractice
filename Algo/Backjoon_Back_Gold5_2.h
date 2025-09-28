#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string str;
int max_num, len;
int arr[51];
vector<int>v;


void func(int n) {
    if (n == len) {
        for (int i = 0; i < max_num; i++) {
            cout << v[i] << " ";
        }
        exit(0);
    }
    int num;
    string s = "";

    for (int i = n; i <= n + 1; i++) {

        s = s + str[i];
        num = stoi(s);
        if (num > max_num) continue;
        if (arr[num])continue;
        v.push_back(num);
        arr[num] = 1;
        func(i + 1);
        arr[num] = 0;
        v.pop_back();

    }

}


int main() {
    cin >> str;
    len = str.length();

    if (len > 9)
        max_num = 9 + (len - 9) / 2;
    else
        max_num = len;

    for (int i = 1; i <= 50; i++)arr[i] = 0;

    func(0);
}
