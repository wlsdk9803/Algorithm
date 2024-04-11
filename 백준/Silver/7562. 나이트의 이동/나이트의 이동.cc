#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

bool isValid(int row, int col, int n) {
	return row >= 0 && row < n && col >= 0 && col < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test; cin >> test;
	for (int t = 0; t < test; t++) {
		int n; cin >> n;
		vector<vector<int>> board(n, vector<int>(n));
		vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
		vector<vector<bool>> visited(n, vector<bool>(n));
		int start_row, start_col, end_row, end_col;
		cin >> start_row >> start_col >> end_row >> end_col;
		queue<pair<int, int>> q;
		q.push({ start_row, start_col });
		visited[start_row][start_col] = true;
		dist[start_row][start_col] = 0;
		while (!q.empty()) {
			int cur_row = q.front().first;
			int cur_col = q.front().second; q.pop();
			if (cur_row == end_row && cur_col == end_col) break;
			for (int i = 0; i < 8; i++) {
				int next_row = cur_row + dy[i];
				int next_col = cur_col + dx[i];
				if (isValid(next_row, next_col, n) && !visited[next_row][next_col]) {
					q.push({ next_row, next_col });
					visited[next_row][next_col] = true;
					dist[next_row][next_col] = min(dist[cur_row][cur_col] + 1, dist[next_row][next_col]);
				}
			}

		}
		cout << dist[end_row][end_col] << "\n";
	}
	return 0;
}