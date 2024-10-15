#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	int cheese = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheese++;
		}
	}
	int final_cheese = 0, time = 0;
	vector<vector<bool>> visited(N, vector<bool>(M));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	while (cheese > 0) {
		set<pair<int, int>> temp;
		while (!q.empty()) {
			int crow = q.front().first;
			int ccol = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int nrow = crow + dy[i];
				int ncol = ccol + dx[i];
				if (isValid(nrow, ncol) && !visited[nrow][ncol]) {
					if (map[nrow][ncol] == 1) temp.insert({ nrow, ncol });
					else {
						q.push({ nrow, ncol });
						visited[nrow][ncol] = true;
					}
				}
			}
		}
		time++;
		cheese -= temp.size();
		if (cheese == 0) final_cheese = temp.size();
		for (pair<int, int> cur : temp) {
			map[cur.first][cur.second] = 0;
			q.push(cur);
		}
	}
	cout << time << "\n" << final_cheese;
	return 0;
}