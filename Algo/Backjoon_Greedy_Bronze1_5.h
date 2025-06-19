#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool flag;

int main() {
    int n;

    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        if (v.empty() || num % 2 != flag) {
            v.push_back(num);
        }


        if (num % 2) {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    cout << v.size();
}