#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Calc(int num) {
    // 짝수라면 true, 홀수라면 false
    return num % 2 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int max_len = 0;  // 최대 연속 짝수 부분 수열의 길이

    int l = 0;  // 왼쪽 포인터
    int odd_count = 0;  // 현재 구간에서의 홀수 개수

    // 두 포인터를 이용한 슬라이딩 윈도우
    for (int r = 0; r < N; ++r) {
        // 현재 r이 가리키는 값이 홀수라면
        if (S[r] % 2 != 0) {
            odd_count++;
        }

        // 홀수의 개수가 K를 초과하면, l 포인터를 증가시켜 구간을 좁힘
        while (odd_count > K) {
            if (S[l] % 2 != 0) {
                odd_count--;
            }
            l++;
        }

        // 유효한 구간의 길이를 계산
        max_len = max(max_len, r - l + 1);
    }

    cout << max_len << endl;
    return 0;
}
