#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isValid(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(N));
	vector<pair<int, int>> chicken;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	vector<int> v;
	int min_sum = 1 << 31 - 1;
	for (int i = 0; i < chicken.size() - M; i++) v.push_back(0);
	for (int i = 0; i < M; i++) v.push_back(1);
	do {
		vector<pair<int, int>> selected_chicken;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) selected_chicken.push_back(chicken[i]);
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int dist = 1 << 31 - 1;
				if (map[i][j] == 1) {
					for (auto &pos : selected_chicken) dist = min(abs(pos.first - i) + abs(pos.second - j), dist);
					sum += dist;
				}
			}
		}
		min_sum = sum < min_sum ? sum : min_sum;
	} while (next_permutation(v.begin(), v.end()));
	cout << min_sum;
	return 0;
}