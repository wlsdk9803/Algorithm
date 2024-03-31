#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool isValid(int row, int col, int M, int N) {
	return row >= 0 && row < M && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M, N, K; cin >> M >> N >> K;
	vector<vector<bool>> visited(M, vector<bool>(N));
	for (int idx = 0; idx < K; idx++) {
		int x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		int width = x2 - x1, height = y2 - y1;
		for (int i = M - y2; i < (M - y2) + height; i++) {
			for (int j = x1; j < x1 + width; j++) visited[i][j] = true;
		}
	}
	vector<int> store_size;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int count = 0;
				stack<pair<int, int>> s;
				s.push({ i,j });
				visited[i][j] = true;
				while (!s.empty()) {
					int row = s.top().first;
					int col = s.top().second;
					count++; s.pop();
					for (int k = 0; k < 4; k++) {
						int next_row = row + dy[k];
						int next_col = col + dx[k];
						if (isValid(next_row, next_col, M, N) && !visited[next_row][next_col]) {
							s.push({ next_row, next_col });
							visited[next_row][next_col] = true;
						}
					}
				}
				store_size.push_back(count);
			}
		}
	}
	sort(store_size.begin(), store_size.end());
	cout << store_size.size() << "\n";
	for (int i = 0; i < store_size.size(); i++) cout << store_size[i] << " ";
	return 0;
}