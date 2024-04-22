#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int n, m;

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') continue;
			vector<vector<bool>> visited(n, vector<bool>(m, false));
			vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			dist[i][j] = 0;
			while (!q.empty()) {
				int row = q.front().first;
				int col = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nrow = row + dy[k];
					int ncol = col + dx[k];
					if (isValid(nrow, ncol) && !visited[nrow][ncol] && map[nrow][ncol] == 'L') {
						dist[nrow][ncol] = min(dist[nrow][ncol], dist[row][col] + 1);
						q.push({ nrow, ncol });
						visited[nrow][ncol] = true;
						res = max(res, dist[nrow][ncol]);
					}
				}
			}
		}
	}
	cout << res;
	return 0;
}