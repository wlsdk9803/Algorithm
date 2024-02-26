#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < M; i++) v.push_back({ map[0][i], {i, -10} });
	for (int i = 1; i < N; i++) {
		vector<pair<int, pair<int, int>>> v_temp;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < v.size(); k++) {
				int dir = j - v[k].second.first;
				if (dir > 1 || dir == v[k].second.second) continue;
				if (dir < -1) break;
				v_temp.push_back({ map[i][j] + v[k].first, {j, dir} });
			}
		}
		v = v_temp;
	}
	sort(v.begin(), v.end());
	cout << v[0].first;
	return 0;
}