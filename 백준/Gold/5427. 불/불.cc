#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int h, int w, int row, int col) {
	return row >= 0 && row < h && col >= 0 && col < w;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int w, h; cin >> w >> h;
		vector<vector<char>> v(h, vector<char>(w));
		vector<vector<bool>> visited_sang(h, vector<bool>(w));
		vector<vector<bool>> visited_fire(h, vector<bool>(w));
		vector<vector<int>> time(h, vector<int>(w, 1 << 30));
		queue<pair<int, int>> q_sang;
		queue<pair<int, int>> q_fire;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> v[i][j];
				if (v[i][j] == '*') {
					q_fire.push({ i, j });
					visited_fire[i][j] = true;
				}
				else if (v[i][j] == '@') {
					q_sang.push({ i, j });
					visited_sang[i][j] = true;
					time[i][j] = 0;
				}
			}
		}
		bool isPossible = false;
		while (!q_sang.empty()) {
			int sang_n = q_sang.size();
			for (int k = 0; k < sang_n; k++) {
				int crow = q_sang.front().first;
				int ccol = q_sang.front().second; q_sang.pop();
				if (crow == 0 || ccol == 0 || crow == h - 1 || ccol == w - 1) {
					cout << time[crow][ccol] + 1 << "\n";
					isPossible = true;  break;
				}
				for (int i = 0; i < 4; i++) {
					int nrow = crow + dy[i];
					int ncol = ccol + dx[i];
					if (isValid(h, w, nrow, ncol) && !visited_sang[nrow][ncol] && v[nrow][ncol] == '.') {
						bool isnextfire = false;
						for (int j = 0; j < 4; j++) {
							int nnrow = nrow + dy[j];
							int nncol = ncol + dx[j];
							if (isValid(h, w, nnrow, nncol) && visited_fire[nnrow][nncol]) {
								isnextfire = true; break;
							}
						}
						if (!isnextfire) {
							q_sang.push({ nrow, ncol });
							visited_sang[nrow][ncol] = true;
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
					if (isValid(h, w, nfrow, nfcol) && !visited_fire[nfrow][nfcol] && v[nfrow][nfcol] != '#') {
						visited_fire[nfrow][nfcol] = true;
						q_fire.push({ nfrow, nfcol });
					}
				}
			}
		}
		if (!isPossible) cout << "IMPOSSIBLE\n";
	}
	return 0;
}