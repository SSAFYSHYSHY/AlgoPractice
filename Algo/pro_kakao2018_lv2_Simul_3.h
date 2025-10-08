#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Node {
    string name;
    int idx;
    int len;
};

bool cmp(Node& a, Node& b) {
    if (a.len == b.len) return a.idx < b.idx;
    return a.len > b.len;
}

string convert(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && s[i + 1] == '#') {
            res += tolower(s[i]);
            i++;
        }
        else res += s[i];
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    vector<Node> v;
    m = convert(m);

    for (int i = 0; i < musicinfos.size(); i++) {
        int first = musicinfos[i].find(',');
        int second = musicinfos[i].find(',', first + 1);
        int third = musicinfos[i].find(',', second + 1);

        string sh = musicinfos[i].substr(0, 2);
        string sm = musicinfos[i].substr(3, 2);
        string eh = musicinfos[i].substr(6, 2);
        string em = musicinfos[i].substr(9, 2);

        int play = (stoi(eh) * 60 + stoi(em)) - (stoi(sh) * 60 + stoi(sm));

        string name = musicinfos[i].substr(second + 1, third - second - 1);
        string sheet = convert(musicinfos[i].substr(third + 1));

        string full;
        for (int j = 0; j < play; j++)
            full += sheet[j % sheet.size()];

        if (full.find(m) != string::npos)
            v.push_back({ name, i, play });
    }

    if (v.empty()) return "None";
    sort(v.begin(), v.end(), cmp);
    return v[0].name;
}
