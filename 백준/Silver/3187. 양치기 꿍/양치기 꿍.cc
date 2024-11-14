#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int R, C;

bool isvalid(int row, int col) {
	return row >= 0 && row < R && col >= 0 && col < C;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	vector<vector<char>> map(R, vector<char>(C));
	vector<vector<bool>> visited(R, vector<bool>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> map[i][j];
	}
	int sheep = 0, wolf = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '#' || visited[i][j]) continue;
			int temp_sheep = 0, temp_wolf = 0;
			queue<pair<int, int>> q;
			q.push({ i, j }); visited[i][j] = true;
			while (!q.empty()) {
				int crow = q.front().first;
				int ccol = q.front().second; q.pop();
				if (map[crow][ccol] == 'v') temp_wolf++;
				else if (map[crow][ccol] == 'k') temp_sheep++;
				for (int k = 0; k < 4; k++) {
					int nrow = crow + dy[k];
					int ncol = ccol + dx[k];
					if (isvalid(nrow, ncol) && !visited[nrow][ncol] && map[nrow][ncol] != '#') {
						q.push({ nrow, ncol });
						visited[nrow][ncol] = true;
					}
				}
			}
			if (temp_sheep > temp_wolf) temp_wolf = 0;
			else temp_sheep = 0;
			sheep += temp_sheep;
			wolf += temp_wolf;
		}
	}
	cout << sheep << " " << wolf;
	return 0;
}