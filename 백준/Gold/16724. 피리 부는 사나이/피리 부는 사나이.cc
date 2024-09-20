#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<char>> v(N, vector<char>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	vector<vector<vector<pair<int, int>>>> edge(N, vector<vector<pair<int, int>>>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			switch (v[i][j]) {
			case 'D':
				edge[i][j].push_back({ i + 1, j });
				edge[i + 1][j].push_back({ i, j });
				break;
			case 'U':
				edge[i][j].push_back({ i - 1, j });
				edge[i - 1][j].push_back({ i, j });
				break;
			case 'R':
				edge[i][j].push_back({ i, j + 1 });
				edge[i][j + 1].push_back({ i, j });
				break;
			case 'L':
				edge[i][j].push_back({ i, j - 1 });
				edge[i][j - 1].push_back({ i, j });
				break;
			}
		}
	}
	queue<pair<int, int>> q;
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			q.push({ i, j });
			visited[i][j] = true;
			while (!q.empty()) {
				int cur_row = q.front().first;
				int cur_col = q.front().second; q.pop();
				for (int k = 0; k < edge[cur_row][cur_col].size(); k++) {
					pair<int, int> next = edge[cur_row][cur_col][k];
					if (!visited[next.first][next.second]) {
						q.push(next);
						visited[next.first][next.second] = true;
					}
				}
			}
			res++;
		}
	}
	cout << res;
	return 0;
}