#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isValid(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, L, R; cin >> N >> L >> R;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}

	int day = 0;
	while (true) {
		bool move = false;
		vector<vector<bool>> visited(N, vector<bool>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					stack<pair<int, int>> s;
					stack<pair<int, int>> temp; //인구 수 갱신을 위한 스택
					int sum = 0, count = 0;
					s.push({ i, j }); temp.push({ i, j });
					visited[i][j] = true;
					while (!s.empty()) {
						int cur_row = s.top().first;
						int cur_col = s.top().second;
						sum += v[cur_row][cur_col]; count++;
						s.pop();
						for (int k = 0; k < 4; k++) {
							int next_row = cur_row + dy[k];
							int next_col = cur_col + dx[k];
							if (isValid(next_row, next_col, N)) {
								int diff = abs(v[cur_row][cur_col] - v[next_row][next_col]);
								if (!visited[next_row][next_col] && L <= diff && diff <= R) {
									s.push({ next_row, next_col });
									temp.push({ next_row, next_col });
									visited[next_row][next_col] = true;
								}
							}
						}
					}
					int avg = sum / count;
					if (temp.size() >= 2) {
						move = true;
						while (!temp.empty()) {
							int row = temp.top().first;
							int col = temp.top().second;
							temp.pop();
							v[row][col] = avg;
						}
					}
				}
			}
		}
		if (!move) break;
		day++;
	}
	cout << day;
	return 0;
}