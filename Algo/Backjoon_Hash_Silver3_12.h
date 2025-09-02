#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N, P, W, L, G;
unordered_map<string, int> MAP;
int Score = 0;
bool Answer = false;

void Input() {
    cin >> N >> P;
    cin >> W >> L >> G;
    for (int i = 0; i < P; i++) {
        string Name, Result;
        cin >> Name >> Result;
        if (Result == "W") MAP[Name] = W;
        else MAP[Name] = -L;
    }
}

void Settings() {
    for (int i = 0; i < N; i++) {
        string Name;
        cin >> Name;
        if (MAP.find(Name) != MAP.end()) Score += MAP[Name];
        else Score -= L;

        if (Score < 0) Score = 0;
        if (Score >= G) Answer = true;
    }
}

void Find_Answer() {
    if (Answer) cout << "I AM NOT IRONMAN!!\n";
    else cout << "I AM IRONMAN!!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Settings();
    Find_Answer();
}
