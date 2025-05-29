#pragma once
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int arr[1000001];
int ans[1000001];

stack<int> s;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {

        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

}

