#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int M, N;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}
	int res = 0;
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];
			if (isValid(nrow, ncol) && box[nrow][ncol] == 0 && !visited[nrow][ncol]) {
				dist[nrow][ncol] = min(dist[nrow][ncol], dist[row][col] + 1);
				q.push({ nrow, ncol });
				visited[nrow][ncol] = true;
				res = max(res, dist[nrow][ncol]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0 && dist[i][j] == INT_MAX) {
				cout << -1; return 0;
			}
		}
	}
	cout << res;
	return 0;
}
