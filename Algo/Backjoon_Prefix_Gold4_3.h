#pragma once
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long n, k, ans = 0;
long long arr[200001];
long long prefix[200001];

int main() {
    cin >> n >> k;

    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];

        prefix[i] = prefix[i - 1] + arr[i];
    }

    // map을 사용하여 prefix 값의 개수를 기록
    map<long long, long long> m;

    for (long long i = 0; i < n + 1; i++) {
        // prefix[i] - k 값이 이전에 존재했다면, 
        //그만큼 부분 배열의 합이 k가 되는 부분 수가 증가
        ans += m[prefix[i] - k];

        // prefix[i] 값을 map에서 카운트 증가
        m[prefix[i]]++;
    }

    // 결과 출력
    cout << ans;
}
