#pragma once
#include <iostream>

using namespace std;

int main() {
    int num;

    while (cin >> num && num != 0) {
        int l = 2, r = 100;
        int cnt = 1;
        int curr = 50;

        while (curr != num) {
            if ((curr % 2) != (num % 2)) {
                // ���� �ǳʱ�
                if (num % 2 == 1) {
                    l = 1;
                    r = 99;
                }
                else {
                    l = 2;
                    r = 100;
                }
            }
            else {
                // ���� ���ο��� Ž��
                if (num < curr) {
                    r = curr - 2;
                }
                else {
                    l = curr + 2;
                }
            }

            // �߾� ��� �� ¦/Ȧ ����
            curr = l + (r - l) / 2;
            if (curr % 2 != num % 2) curr--;
            cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
