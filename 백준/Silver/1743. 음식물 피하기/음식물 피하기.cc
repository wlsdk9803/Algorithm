#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K; cin >> N >> M >> K;
	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < K; i++) {
		int r, c; cin >> r >> c;
		v[--r][--c] = 1;
	}
	int max_food = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!v[i][j]) continue;
			stack<pair<int, int>> s;
			vector<vector<bool>> visited(N, vector<bool>(M));
			s.push({ i, j });
			visited[i][j] = true;
			int food = 1;
			while (!s.empty()) {
				int row = s.top().first;
				int col = s.top().second; s.pop();
				for (int i = 0; i < 4; i++) {
					int nrow = row + dy[i];
					int ncol = col + dx[i];
					if (isValid(nrow, ncol) && !visited[nrow][ncol] && v[nrow][ncol]) {
						s.push({ nrow, ncol });
						visited[nrow][ncol] = true;
						food++;
					}
				}
			}
			max_food = max(max_food, food);
		}
	}
	cout << max_food;
	return 0;
}