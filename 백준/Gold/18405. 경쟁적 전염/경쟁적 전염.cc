#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isvalid(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<vector<int>> v(N, vector<int>(N));
	vector<pair<int, pair<int, int>>> temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			if (v[i][j] > 0) temp.push_back({ v[i][j], {i, j} });
		}
	}
	int S, X, Y; cin >> S >> X >> Y;
	sort(temp.begin(), temp.end());
	queue<pair<int, int>> q;
	for (auto& elem : temp) q.push(elem.second);
	int time = 0;
	while (true) {
		if (time == S) break;
		queue<pair<int, int>> temp;
		while (!q.empty()) {
			int crow = q.front().first;
			int ccol = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int nrow = crow + dy[i];
				int ncol = ccol + dx[i];
				if (isvalid(nrow, ncol, N) && v[nrow][ncol] == 0) {
					v[nrow][ncol] = v[crow][ccol];
					temp.push({ nrow, ncol });
				}
			}
		}
		time++;
		q = temp;
	}
	cout << v[X - 1][Y - 1];
	return 0;
}