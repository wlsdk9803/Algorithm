#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
queue<pair<int, int>> virus;

bool isvalid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int bfs(vector<vector<int>> map) {
	int count = 0;
	vector<vector<bool>> visited(N, vector<bool>(M));
	queue<pair<int, int>> q;
	while (!virus.empty()) {
		q.push(virus.front());
		visited[virus.front().first][virus.front().second] = true;
		virus.pop();
	}
	virus = q;
	while (!q.empty()) {
		int crow = q.front().first, ccol = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nrow = crow + dy[i];
			int ncol = ccol + dx[i];
			if (isvalid(nrow, ncol) && map[nrow][ncol] != 1 && !visited[nrow][ncol]) {
				map[nrow][ncol] = 2;
				visited[nrow][ncol] = true;
				q.push({ nrow, ncol });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) count++;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	vector<pair<int, int>> pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) pos.push_back({ i, j });
			else if (map[i][j] == 2) virus.push({ i, j });
		}
	}
	int res = 0;
	vector<int> v;
	for (int i = 0; i < pos.size() - 3; i++) v.push_back(0);
	for (int i = 0; i < 3; i++) v.push_back(1);
	do {
		vector<pair<int, int>> temp_pos;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) temp_pos.push_back(pos[i]);
		}
		vector<vector<int>> temp_map = map;
		for (int i = 0; i < temp_pos.size(); i++) {
			int row = temp_pos[i].first, col = temp_pos[i].second;
			temp_map[row][col] = 1;
		}
		res = max(res, bfs(temp_map));
	} while (next_permutation(v.begin(), v.end()));
	cout << res;
	return 0;
}