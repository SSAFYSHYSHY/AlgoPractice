#pragma once
#include <string>
#include <vector>
#include <stack> 
#include <algorithm>
#include <iostream>

using namespace std;

stack<int> st;
int arr[31][31], n = 0;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    n = board.size();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            arr[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        int idx = moves[i];
        idx--;

        for (int j = 0; j < n; j++) {
            //0이 아닌 수를 맞이하면
            if (arr[j][idx] != 0) {
                int num = arr[j][idx];
                arr[j][idx] = 0;

                //같은 수면.
                if (!st.empty() && num == st.top()) {
                    answer += 2;
                    st.pop();
                }
                //다른 수면.
                else {
                    st.push(num);
                }

                break;
            }
        }

    }


    return answer;
}