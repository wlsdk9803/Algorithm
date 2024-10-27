#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M));
	vector<vector<int>> res(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && !visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = true;
				int count = 1;
				vector<pair<int, int>> walls;
				while (!q.empty()) {
					int crow = q.front().first;
					int ccol = q.front().second; q.pop();
					for (int k = 0; k < 4; k++) {
						int nrow = crow + dy[k];
						int ncol = ccol + dx[k];
						if (isValid(nrow, ncol) && !visited[nrow][ncol]) {
							if (!map[nrow][ncol]) {
								q.push({ nrow, ncol });
								count++;
							}
							else walls.push_back({ nrow, ncol });
							visited[nrow][ncol] = true;
						}
					}
				}
				for (pair<int, int> wall : walls) {
					int row = wall.first;
					int col = wall.second;
					res[row][col] += count;
					visited[row][col] = false;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) cout << 0;
			else cout << (res[i][j] + 1) % 10;
		}
		cout << "\n";
	}
	return 0;
}