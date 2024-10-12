#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int test = 0; test < t; test++) {
		int n; cin >> n;
		vector<pair<int, int>> stores(n);
		pair<int, int> home; cin >> home.first >> home.second;
		for (int i = 0; i < n; i++) cin >> stores[i].first >> stores[i].second;
		pair<int, int> festival; cin >> festival.first >> festival.second;

		queue<pair<int, int>> q;
		set<pair<int, int>> visited;
		q.push(home); visited.insert(home);
		bool ishappy = false;
		while (!q.empty()) {
			int x = q.front().first; int y = q.front().second; q.pop();
			if (abs(x - festival.first) + abs(y - festival.second) <= 1000) {
				ishappy = true; break;
			}
			for (pair<int, int> store : stores) {
				if (visited.find(store) != visited.end()) continue;
				if (abs(x - store.first) + abs(y - store.second) <= 1000) {
					q.push(store);
					visited.insert(store);
				}
			}
		}
		if (ishappy) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}