#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> answerGroupSizes;

bool isPossible(int mid) {
    vector<int> tempGroupSizes;
    int cnt = 1;
    int sum = 0;
    int groupSize = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false;

        if (sum + arr[i] > mid) {
            tempGroupSizes.push_back(groupSize);
            cnt++;
            sum = arr[i];
            groupSize = 1;
        }
        else {
            sum += arr[i];
            groupSize++;
        }
    }

    tempGroupSizes.push_back(groupSize); // 마지막 그룹

    if (cnt <= m) {
        answerGroupSizes = tempGroupSizes;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = *max_element(arr.begin(), arr.end()); // 최소는 가장 큰 값 이상이어야 함
    int r = 300000;
    int answer = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (isPossible(mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer << "\n";

    // 그룹 개수 보정 (정확히 m개가 되도록)
    int remainingGroups = m - answerGroupSizes.size();
    vector<int> finalGroups;

    for (int i = 0; i < answerGroupSizes.size(); i++) {
        while (answerGroupSizes[i] > 1 && remainingGroups > 0) {
            finalGroups.push_back(1);
            answerGroupSizes[i]--;
            remainingGroups--;
        }
        finalGroups.push_back(answerGroupSizes[i]);
    }

    for (int i = 0; i < finalGroups.size(); i++) {
        cout << finalGroups[i] << " ";
    }
    cout << "\n";
    return 0;
}
