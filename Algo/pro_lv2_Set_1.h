#pragma once
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (auto& op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            ms.insert(num);
        }
        else if (!ms.empty()) {
            if (op[2] == '1') {
                auto it = prev(ms.end());  // ���� ū ��
                ms.erase(it);
            }
            else {
                auto it = ms.begin();  // ���� ���� ��
                ms.erase(it);
            }
        }
    }

    if (ms.empty()) return { 0, 0 };
    return { *prev(ms.end()), *ms.begin() };
}
