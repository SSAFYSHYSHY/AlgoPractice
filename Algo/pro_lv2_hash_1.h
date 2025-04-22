#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> rightCnt;
    for (int i = 0; i < topping.size(); i++) {
        rightCnt[topping[i]]++;
    }

    unordered_set<int> leftSet;
    for (int i = 0; i < topping.size(); i++) {
        int now = topping[i];
        leftSet.insert(now);

        rightCnt[now]--;
        if (rightCnt[now] == 0) {
            rightCnt.erase(now);
        }

        if (leftSet.size() == rightCnt.size()) {
            answer++;
        }
    }

    return answer;
}