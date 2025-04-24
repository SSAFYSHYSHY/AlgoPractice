#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

unordered_set<int> map;
bool visited[8] = { false, };

bool IsPrime(int num) {
    if (num <= 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void Back(int now, int ans, string temp, string s) {
    if (now == ans) {
        int num = stoi(temp);
        if (IsPrime(num)) {
            map.insert(num);
        }
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            Back(now + 1, ans, temp + s[i], s);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 1; i <= numbers.size(); i++) {
        Back(0, i, "", numbers);
        memset(visited, false, sizeof(visited));
    }

    return map.size();
}