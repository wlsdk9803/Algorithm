#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col, int N, int M) {
	return row >= 0 && row < N && col >= 0 && col < M;
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
	vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(K + 1, max_dist)));
	queue<pair<int, int>> q;
	q.push({ 0, 0 }); dist[0][0][0] = 1;
	while (!q.empty()) {
		int crow = q.front().first;
		int ccol = q.front().second; q.pop();
		if (crow == N - 1 && ccol == M - 1) break;
		for (int i = 0; i < 4; i++) {
			bool ismoved = false;
			int nrow = crow + dy[i];
			int ncol = ccol + dx[i];
			if (isValid(nrow, ncol, N, M)) {
				if (map[nrow][ncol] == 0) {
					for (int j = 0; j <= K; j++) {
						if (dist[nrow][ncol][j] > dist[crow][ccol][j] + 1) {
							dist[nrow][ncol][j] = dist[crow][ccol][j] + 1;
							ismoved = true;
						}
					}
				}
				else {
					for (int j = 1; j <= K; j++) {
						if (dist[nrow][ncol][j] > dist[crow][ccol][j - 1] + 1) {
							dist[nrow][ncol][j] = dist[crow][ccol][j - 1] + 1;
							ismoved = true;
						}
					}
				}
				if (ismoved) q.push({ nrow, ncol });
			}
		}
	}
	int min_dist = max_dist;
	for (int i = 0; i <= K; i++) min_dist = min(min_dist, dist[N - 1][M - 1][i]);
	if (min_dist == max_dist) cout << -1;
	else cout << min_dist;
	return 0;
}