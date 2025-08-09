#pragma once
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(n));
        vector<int> r(n), c(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
                if (i && j)
                    mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
                else if (i)
                    mat[i][j] += mat[i - 1][j];
                else if (j)
                    mat[i][j] += mat[i][j - 1];
            }
        }

        int tmp = n - 1;
        for (int i = 0; i < n; i++) {
            r[i] = mat[i][tmp];
            c[i] = mat[tmp][i];
            if (i) {
                r[i] -= mat[i - 1][tmp];
                c[i] -= mat[tmp][i - 1];
            }
        }

        while (m--) {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;

            int mul = (c2 - c1 + 1) * v;
            for (int i = r1 - 1; i < r2; i++) r[i] += mul;

            mul = (r2 - r1 + 1) * v;
            for (int i = c1 - 1; i < c2; i++) c[i] += mul;
        }

        for (int i = 0; i < n; i++) cout << r[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++) cout << c[i] << " ";
        cout << "\n";
    }

    return 0;
}