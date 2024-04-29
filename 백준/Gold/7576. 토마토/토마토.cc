#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int M, N;
int box[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q; //행, 열
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int x, int y) {
	return (x >= 0 && x < M&& y >= 0 && y < N);
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (!visited[y][x]) {
			visited[y][x] = true;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (box[ny][nx] == 0 && isValid(nx, ny) && !visited[ny][nx]) {
					box[ny][nx] = box[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(box, 0, sizeof(box));
	memset(visited, false, sizeof(visited));
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i, j });
		}
	}
	bfs();
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (box[i][j] > num) num = box[i][j];
		}
	}
	cout << num - 1;
	return 0;
}