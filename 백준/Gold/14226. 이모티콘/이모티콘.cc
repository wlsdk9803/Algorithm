#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

bool isValid(int a, int b, int S) {
    return a >= 0 && a <= 2 * S && b >= 0 && b <= 2 * S;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int S; cin >> S;
    vector<vector<int>> time(2 * S + 1, vector<int>(2 * S + 1, INT_MAX));
    vector<vector<bool>> visited(2 * S + 1, vector<bool>(2 * S + 1));
    queue<pair<int, int>> q; // 이모티콘, 클립보드
    q.push({ 1, 0 });
    time[1][0] = 0;
    visited[1][0] = true;
    int res = 0;
    while (!q.empty()) {
        int cur_emo = q.front().first;
        int cur_clip = q.front().second; q.pop();
        if (cur_emo == S) {
            res = time[cur_emo][cur_clip];
            break;
        }
        for (int i = 0; i < 3; i++) {
            int next_emo = cur_emo, next_clip = cur_clip;
            if (i == 0) next_clip = cur_emo;
            else if(i == 1) next_emo = cur_emo + cur_clip;
            else next_emo = cur_emo - 1;
            if (isValid(next_emo, next_clip, S) && !visited[next_emo][next_clip] && time[next_emo][next_clip] > time[cur_emo][cur_clip] + 1) {
                q.push({ next_emo, next_clip });
                time[next_emo][next_clip] = time[cur_emo][cur_clip] + 1;
                visited[next_emo][next_clip] = true;
            }
        }
    }
    cout << res;
    return 0;
}