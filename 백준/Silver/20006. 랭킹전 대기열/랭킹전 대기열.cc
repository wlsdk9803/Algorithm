#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p, m; cin >> p >> m;
	vector<vector<pair<int, string>>> rooms;
	for (int idx = 0; idx < p; idx++) {
		int level; string n;
		cin >> level >> n;
		bool isin = false;
		for (int i = 0; i < rooms.size(); i++) {
			if (isin) break;
			if (rooms[i].size() < m && abs(rooms[i][0].first - level) <= 10) {
				rooms[i].push_back({ level, n });
				isin = true;
			}
		}
		if (!isin) rooms.push_back({ {level, n} });
	}
	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i].size() == m) cout << "Started!\n";
		else cout << "Waiting!\n";
		sort(rooms[i].begin(), rooms[i].end(), comp);
		for (int j = 0; j < rooms[i].size(); j++) {
			cout << rooms[i][j].first << " " << rooms[i][j].second << "\n";
		}
	}
	return 0;
}