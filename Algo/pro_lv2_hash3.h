#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> makeMultiset(string s) {
    vector<string> result;
    for (int i = 0; i < s.size() - 1; ++i) {
        char a = tolower(s[i]);
        char b = tolower(s[i + 1]);
        if (isalpha(a) && isalpha(b)) {
            result.push_back(string() + a + b);
        }
    }
    return result;
}

int solution(string str1, string str2) {
    vector<string> A = makeMultiset(str1);
    vector<string> B = makeMultiset(str2);

    unordered_map<string, int> A_map, B_map;

    for (auto& s : A) A_map[s]++;
    for (auto& s : B) B_map[s]++;

    int inter = 0, uni = 0;

    for (auto& [key, val] : A_map) {
        if (B_map.count(key)) {
            inter += min(val, B_map[key]);
            uni += max(val, B_map[key]);
        }
        else {
            uni += val;
        }
    }

    for (auto& [key, val] : B_map) {
        if (!A_map.count(key)) {
            uni += val;
        }
    }

    double similarity = (uni == 0) ? 1.0 : (double)inter / uni;
    return (int)(similarity * 65536);
}