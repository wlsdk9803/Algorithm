#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<pair<int, int>, pair<int, int>> v1, pair<pair<int, int>, pair<int, int>> v2) {
	if (v1.first.second != v2.first.second) return v1.first.second > v2.first.second;
	if (v1.second.first != v2.second.first) return v1.second.first < v2.second.first;
	return v1.second.second < v2.second.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		vector<vector<int>> log(n + 1, vector<int>(k));
		vector<pair<pair<int, int>, pair<int, int>>> total(n + 1); //{팀id, 총점}, {제출횟수, 마지막 제출 시간}
		for (int i = 1; i < n + 1; i++) total[i].first.first = i;
		for (int entry = 0; entry < m; entry++) {
			int i, j, s; cin >> i >> j >> s;
			if (log[i][j - 1] < s) {
				total[i].first.second += (s - log[i][j - 1]);
				log[i][j - 1] = s;
			}
			total[i].second.first++;
			total[i].second.second = entry;
		}
		sort(total.begin(), total.end(), comp);
		for (int i = 0; i < n + 1; i++) {
			if (total[i].first.first == t) cout << i + 1 << "\n";
		}
	}
	return 0;
}