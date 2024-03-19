#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, P, X;

vector<int> split_num(int num) {
    vector<int> result;
    while (num > 9) {
        result.push_back(num % 10);
        num /= 10;
    }
    result.push_back(num);
    while (result.size() < K) result.push_back(0);
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> P >> X;
    vector<vector<int>> digit(10);
    digit[0] = { 1,2,3,4,5,6 }, digit[1] = { 1,6 }, digit[2] = { 0,1,2,4,5 }, digit[3] = { 0,1,2,5,6 }, digit[4] = { 0,1,3,6 }, digit[5] = { 0,2,3,5,6 }, digit[6] = { 0,2,3,4,5,6 }, digit[7] = { 1,2,6 }, digit[8] = { 0,1,2,3,4,5,6 }, digit[9] = { 0,1,2,3,5,6 };
    vector<vector<int>> change(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) change[i][j] = 0;
            else {
                int count = 0;
                for (int k = 0; k < 10; k++) {
                    int isfind_i = -1, isfind_j = -1;
                    if (find(digit[i].begin(), digit[i].end(), k) != digit[i].end()) isfind_i = 1; // k가 존재하면 1
                    if (find(digit[j].begin(), digit[j].end(), k) != digit[j].end()) isfind_j = 1;
                    if (isfind_i * isfind_j == -1) count++;
                }
                change[i][j] = count;
                change[j][i] = count;
            }
        }
    }
    int res = 0;
    vector<int> cur_num = split_num(X);
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        vector<int> comp_num = split_num(i);
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            cnt += change[cur_num[j]][comp_num[j]];
            if (cnt > P) break;
        }
        if (cnt > 0 && cnt <= P) res++;
    }
    cout << res;
    return 0;
}
