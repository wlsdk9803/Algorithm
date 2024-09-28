#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int R, int C, int row, int col) {
	return row >= 0 && row < R && col >= 0 && col < C;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int R, C; cin >> R >> C;
	vector<vector<char>> v(R, vector<char>(C));
	vector<vector<bool>> visited_j(R, vector<bool>(C));
	vector<vector<bool>> visited_fire(R, vector<bool>(C));
	vector<vector<int>> time(R, vector<int>(C, 1 << 30));
	queue<pair<int, int>> q_j;
	queue<pair<int, int>> q_fire;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'F') {
				q_fire.push({ i, j });
				visited_fire[i][j] = true;
			}
			else if (v[i][j] == 'J') {
				q_j.push({ i, j });
				visited_j[i][j] = true;
				time[i][j] = 0;
			}
		}
	}
	bool isPossible = false;
	while (!q_j.empty()) {
		int j_n = q_j.size();
		for (int k = 0; k < j_n; k++) {
			int crow = q_j.front().first;
			int ccol = q_j.front().second; q_j.pop();
			if (crow == 0 || ccol == 0 || crow == R - 1 || ccol == C - 1) {
				cout << time[crow][ccol] + 1 << "\n";
				isPossible = true;  break;
			}
			for (int i = 0; i < 4; i++) {
				int nrow = crow + dy[i];
				int ncol = ccol + dx[i];
				if (isValid(R, C, nrow, ncol) && !visited_j[nrow][ncol] && v[nrow][ncol] == '.') {
					bool isnextfire = false;
					for (int j = 0; j < 4; j++) {
						int nnrow = nrow + dy[j];
						int nncol = ncol + dx[j];
						if (isValid(R, C, nnrow, nncol) && visited_fire[nnrow][nncol]) {
							isnextfire = true; break;
						}
					}
					if (!isnextfire) {
						q_j.push({ nrow, ncol });
						visited_j[nrow][ncol] = true;
						time[nrow][ncol] = min(time[nrow][ncol], time[crow][ccol] + 1);
					}
				}
			}
		}
		if (isPossible) break;
		int fire_n = q_fire.size();
		for (int k = 0; k < fire_n; k++) {
			int frow = q_fire.front().first;
			int fcol = q_fire.front().second; q_fire.pop();
			for (int i = 0; i < 4; i++) {
				int nfrow = frow + dy[i];
				int nfcol = fcol + dx[i];
				if (isValid(R, C, nfrow, nfcol) && !visited_fire[nfrow][nfcol] && v[nfrow][nfcol] != '#') {
					visited_fire[nfrow][nfcol] = true;
					q_fire.push({ nfrow, nfcol });
				}
			}
		}
	}
	if (!isPossible) cout << "IMPOSSIBLE\n";
	return 0;
}