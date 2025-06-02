#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd

using namespace std;

int main() {
    int N;
    long long S;
    cin >> N >> S;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] = abs(A[i] - S); // 각 동생과의 거리 절댓값
    }

    // 거리 차들의 GCD 구하기
    long long D = A[0];
    for (int i = 1; i < N; ++i) {
        D = gcd(D, A[i]);
    }

    cout << D << '\n';
    return 0;
}
