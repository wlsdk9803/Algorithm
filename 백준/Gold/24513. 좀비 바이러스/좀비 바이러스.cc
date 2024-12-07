#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isvalid(int row, int col, int N, int M) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<pair<int, int>>> v(N, vector<pair<int, int>>(M));
	queue<pair<int, int>> q;
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int stat; cin >> stat;
			v[i][j] = { time, stat };
			if (v[i][j].second > 0) q.push({ i, j });
		}
	}
	while (!q.empty()) {
		time++;
		int q_size = q.size();
		for (int s = 0; s < q_size; s++) {
			int crow = q.front().first;
			int ccol = q.front().second; q.pop();
			if (v[crow][ccol].second == -1 || v[crow][ccol].second == 3) continue;
			for (int i = 0; i < 4; i++) {
				int nrow = crow + dy[i];
				int ncol = ccol + dx[i];
				if (isvalid(nrow, ncol, N, M)) {
					if (v[nrow][ncol].second == -1 || v[nrow][ncol].second == 3) continue;
					if (v[nrow][ncol].second == 0) {
						v[nrow][ncol] = { time, v[crow][ccol].second };
						q.push({ nrow, ncol });
					}
					else if (v[crow][ccol].second + v[nrow][ncol].second == 3 && v[nrow][ncol].first == time) {
						v[nrow][ncol] = { time, 3 };
					}
				}
			}
		}
	}
	int fir = 0, sec = 0, third = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (v[i][j].second) {
			case 1:
				fir++; break;
			case 2:
				sec++; break;
			case 3:
				third++; break;
			}
		}
	}
	cout << fir << " " << sec << " " << third;
	return 0;
}