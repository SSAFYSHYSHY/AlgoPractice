#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �Է����� �־��� ������: n�� ���� ��, m�� �׷� ��
int n, m;

// arr: ���� �־��� ���� �迭
// answerGroupSizes: ������ �׷� ������ ����
vector<int> arr;
vector<int> answerGroupSizes;

// Ư�� mid ��(�׷� �ִ� ���� ���Ѽ�)���� �׷��� �������� ��
// �׷� ������ m ���Ϸ� ���������� Ȯ���ϴ� �Լ�
bool isPossible(int mid) {
    vector<int> tempGroupSizes; // ���� mid���� ������ �׷��� ũ����� ����
    int cnt = 1;                // �׷� ����. ������ 1������.
    int sum = 0;                // ���� �׷��� ���� ��
    int groupSize = 0;          // ���� �׷쿡 ���Ե� ���� ��

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false; // � �ϳ��� ���Ұ� mid���� ũ�� �׷� �Ұ���

        // �������� mid�� �ʰ��ϸ� �׷��� ���� ������
        if (sum + arr[i] > mid) {
            tempGroupSizes.push_back(groupSize); // ���ݱ��� ���� �׷� ũ�� ����
            cnt++;                                // �׷� ���� ����
            sum = arr[i];                         // �� �׷� ����
            groupSize = 1;
        }
        else {
            sum += arr[i];   // ���� �׷쿡 ��� ����
            groupSize++;
        }
    }

    // ������ �׷� ó��
    tempGroupSizes.push_back(groupSize);

    // �׷� ������ m ������ ��� ���� �׷� ������ ���� �ĺ��� ����
    if (cnt <= m) {
        answerGroupSizes = tempGroupSizes;
        return true;
    }

    return false; // m���� ������ �Ұ���
}

int main() {
    // �Է� �ޱ�
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // �̺� Ž���� ���� �������� ���� ����
    int l = *max_element(arr.begin(), arr.end()); // �ּҰ��� ���� ū ���� �̻��̾�� ��
    int r = 300000;
    int answer = 0;

    // �̺� Ž�� ����
    while (l <= r) {
        int mid = (l + r) / 2;

        // ���� mid�� �׷��� �����ϸ� �� ���� mid�� �õ�
        if (isPossible(mid)) {
            answer = mid;   // ������ ���� ���� �ĺ� ����
            r = mid - 1;    // �� ���� mid �õ�
        }
        else {
            l = mid + 1;    // �Ұ����ϹǷ� �� ū mid �õ�
        }
    }

    // �ּ� ������ �ִ� �׷� �� ���
    cout << answer << "\n";

    // m���� �׷��� �ǵ��� �׷� �� ����
    // ���� answerGroupSizes�� m���� ���� ���� �����Ƿ� 1�� �ɰ��� ����
    int remainingGroups = m - answerGroupSizes.size();
    vector<int> finalGroups;

    for (int i = 0; i < answerGroupSizes.size(); i++) {
        // �׷��� ũ�Ⱑ 1���� ũ��, ���� �׷� ���� ���� �� 1�� �ɰ���
        while (answerGroupSizes[i] > 1 && remainingGroups > 0) {
            finalGroups.push_back(1);
            answerGroupSizes[i]--;
            remainingGroups--;
        }
        finalGroups.push_back(answerGroupSizes[i]); // �������� �״�� ����
    }

    // ���� �׷� ũ�� ���
    for (int i = 0; i < finalGroups.size(); i++) {
        cout << finalGroups[i] << " ";
    }
    cout << "\n";

    return 0;
}
