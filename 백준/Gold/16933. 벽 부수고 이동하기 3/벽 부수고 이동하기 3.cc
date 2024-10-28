#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col, int N, int M) {
	return row >= 0 && row < N&& col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_dist = 1000 * 1000 + 1;
	int N, M, K; cin >> N >> M >> K;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K + 1)));
	queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q; // row, col, 이동거리, 부순 벽 개수, 낮(0) or 밤(1)
	q.push({ {0, 0}, {1, {0, 0} } }); visited[0][0][0] = true;
	int res = max_dist;
	while (!q.empty()) {
		int crow = q.front().first.first;
		int ccol = q.front().first.second;
		int dist = q.front().second.first;
		int broken = q.front().second.second.first;
		int isnight = q.front().second.second.second; q.pop();
		if (crow == N - 1 && ccol == M - 1) {
			res = dist; break;
		}
		for (int i = 0; i < 4; i++) {
			int nrow = crow + dy[i];
			int ncol = ccol + dx[i];
			if (isValid(nrow, ncol, N, M)) {
				if (map[nrow][ncol] == 0 && !visited[nrow][ncol][broken]) {
					visited[nrow][ncol][broken] = true;
					q.push({ { nrow, ncol }, { dist + 1, {broken, !isnight} } });
				}
				else if (map[nrow][ncol] == 1 && broken < K && !visited[nrow][ncol][broken + 1]) {
					if (!isnight) {
						visited[nrow][ncol][broken + 1] = true;
						q.push({ { nrow, ncol }, { dist + 1, {broken + 1, !isnight} } });
					}
					else q.push({ {crow, ccol}, {dist + 1, {broken, !isnight}} });
				}
			}
		}
	}
	if (res == max_dist) cout << -1;
	else cout << res;
	return 0;
}