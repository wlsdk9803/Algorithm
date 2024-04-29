#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int M, N, H;
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

bool isValid(int row, int col, int height) {
	return row >= 0 && row < N && col >= 0 && col < M && height >= 0 && height < H;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N >> H;
	vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
	vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M)));
	vector<vector<vector<int>>> dist(H, vector<vector<int>>(N, vector<int>(M, INT_MAX)));
	queue<pair<int, pair<int, int>>> q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) {
					q.push({ k, { i, j } });
					dist[k][i][j] = 0;
					visited[k][i][j] = true;
				}
			}
		}
	}
	
	int res = 0;
	while (!q.empty()) {
		int height = q.front().first;
		int row = q.front().second.first;
		int col = q.front().second.second; q.pop();
		for (int i = 0; i < 6; i++) {
			int nheight = height + dh[i];
			int nrow = row + dy[i];
			int ncol = col + dx[i];
			if (isValid(nrow, ncol, nheight) && box[nheight][nrow][ncol] == 0 && !visited[nheight][nrow][ncol]) {
				dist[nheight][nrow][ncol] = min(dist[nheight][nrow][ncol], dist[height][row][col] + 1);
				q.push({ nheight, { nrow, ncol } });
				visited[nheight][nrow][ncol] = true;
				res = max(res, dist[nheight][nrow][ncol]);
			}
		}
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[k][i][j] == 0 && dist[k][i][j] == INT_MAX) {
					cout << -1; return 0;
				}
			}
		}
	}
	cout << res;
	return 0;
}