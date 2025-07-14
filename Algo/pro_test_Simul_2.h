#pragma once
#include <string>
#include <vector>

using namespace std;

int toSec(string s) {
    int mm = stoi(s.substr(0, 2));
    int ss = stoi(s.substr(3, 2));
    return mm * 60 + ss;
}

string toStr(int sec) {
    int mm = sec / 60;
    int ss = sec % 60;

    string res;
    if (mm < 10) res += "0";
    res += to_string(mm);
    res += ":";
    if (ss < 10) res += "0";
    res += to_string(ss);
    return res;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int total_len = toSec(video_len);
    int curr = toSec(pos);
    int op_s = toSec(op_start);
    int op_e = toSec(op_end);

    if (op_s <= curr && curr <= op_e) curr = op_e;

    for (string cmd : commands) {
        if (cmd == "prev") {
            curr = max(0, curr - 10);
        }
        else if (cmd == "next") {
            curr = min(total_len, curr + 10);
        }

        if (op_s <= curr && curr <= op_e) curr = op_e;
    }

    return toStr(curr);
}
