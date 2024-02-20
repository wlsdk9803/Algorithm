#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int R, C;

bool isValid(int row, int col) {
	return row >= 0 && row < R && col >= 0 && col < C;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	vector<vector<char>> map(R, vector<char>(C));
	vector<vector<bool>> visited(R, vector<bool>(C));
	vector<vector<bool>> water_visited(R, vector<bool>(C));
	vector<vector<int>> water_dist(R, vector<int>(C, INT_MAX));
	vector<vector<int>> dist(R, vector<int>(C));
	queue<pair<int, int>> q;
	queue<pair<int, int>> water_q;
	pair<int, int> cave; //굴 좌표
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push({ i, j });
				visited[i][j] = true;
			}
			else if (map[i][j] == '*') {
				water_q.push({ i, j });
				water_visited[i][j] = true;
				water_dist[i][j] = 0;
			}
			else if (map[i][j] == 'D') cave = { i, j };
		}
	}
	while (!water_q.empty()) {
		int water_row = water_q.front().first;
		int water_col = water_q.front().second;
		water_q.pop();
		for (int i = 0; i < 4; i++) {
			int next_wrow = water_row + dy[i];
			int next_wcol = water_col + dx[i];
			if (isValid(next_wrow, next_wcol) && !water_visited[next_wrow][next_wcol] && map[next_wrow][next_wcol] == '.') {
				water_q.push({ next_wrow, next_wcol });
				water_dist[next_wrow][next_wcol] = water_dist[water_row][water_col] + 1;
				water_visited[next_wrow][next_wcol] = true;
			}
		}
	}
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		if (map[row][col] == 'D') break;
		for (int i = 0; i < 4; i++) {
			int next_row = row + dy[i];
			int next_col = col + dx[i];
			if (isValid(next_row, next_col)) {
				if(map[next_row][next_col] == 'X') continue;
				if (water_dist[next_row][next_col] > dist[row][col] + 1 && !visited[next_row][next_col]) {
					q.push({ next_row, next_col });
					dist[next_row][next_col] = dist[row][col] + 1;
					visited[next_row][next_col] = true;
				}
			}
		}
	}
	if (dist[cave.first][cave.second] == 0) cout << "KAKTUS";
	else cout << dist[cave.first][cave.second];
	return 0;
}