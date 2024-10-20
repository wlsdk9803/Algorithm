#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int horse_dy[] = { 2, 1, 2, 1, -2, -1, -2, -1 };
int horse_dx[] = { 1, 2, -1, -2, 1, 2, -1, -2 };

bool isValid(int row, int col, int H, int W) {
	return row >= 0 && row < H && col >= 0 && col < W;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_dist = 200 * 200 + 1;
	int K; cin >> K;
	int W, H; cin >> W >> H;
	vector<vector<int>> map(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> map[i][j];
	}
	vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, max_dist)));
	queue<pair<int, int>> q;
	q.push({ 0, 0 }); dist[0][0][0] = 0;
	while (!q.empty()) {
		int crow = q.front().first;
		int ccol = q.front().second; q.pop();
		if (crow == H - 1 && ccol == W - 1) break;
		for (int i = 0; i < 4; i++) {
			bool ismoved = false;
			int nrow = crow + dy[i];
			int ncol = ccol + dx[i];
			if (isValid(nrow, ncol, H, W) && map[nrow][ncol] == 0) {
				for (int j = 0; j <= K; j++) {
					if (dist[nrow][ncol][j] > dist[crow][ccol][j] + 1) {
						dist[nrow][ncol][j] = dist[crow][ccol][j] + 1;
						ismoved = true;
					}
				}
				if (ismoved) q.push({ nrow, ncol });
			}
		}
		for (int i = 0; i < 8; i++) {
			bool ismoved = false;
			int nrow = crow + horse_dy[i];
			int ncol = ccol + horse_dx[i];
			if (isValid(nrow, ncol, H, W) && map[nrow][ncol] == 0) {
				for (int j = 1; j <= K; j++) {
					if (dist[nrow][ncol][j] > dist[crow][ccol][j - 1] + 1) {
						dist[nrow][ncol][j] = dist[crow][ccol][j - 1] + 1;
						ismoved = true;
					}
				}
				if (ismoved) q.push({ nrow, ncol });
			}
		}
	}
	int min_dist = max_dist;
	for (int i = 0; i <= K; i++) min_dist = min(min_dist, dist[H - 1][W - 1][i]);
	if (min_dist == max_dist) cout << -1;
	else cout << min_dist;
	return 0;
}