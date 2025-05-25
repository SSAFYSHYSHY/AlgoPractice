#include <iostream>
#include <vector>

using namespace std;

int t;
int n, m;
long long arr[1005][1005];
int mod = 1000000009;

long long Back(int n, int m) {
    if (n == 0) return 1;
    if (n < 0 || m == 0) return 0;

    if (arr[n][m] != -1) {
        return arr[n][m];
    }

    long long num = 0;

    for (int i = 1; i < 4; i++) {
        num += Back(n - i, m - 1) % mod;
    }

    arr[n][m] = num % mod;

    return arr[n][m] % mod;
}

int main() {
    cin >> t;
    memset(arr, -1, sizeof(arr));

    while (t--) {
        cin >> n >> m;
        cout << Back(n, m) << '\n';
    }


    return 0;
}