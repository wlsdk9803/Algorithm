#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> degree(N + 1);
	vector<vector<pair<int, int>>> edge(N + 1); // 노드, 횟수
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int X, Y, K; cin >> X >> Y >> K;
		edge[Y].push_back({X, K});
		degree[X] += K;
	}
	unordered_map<int, vector<pair<int, int>>> um;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int count = edge[cur][i].second;
			vector<pair<int, int>> temp;
			if (um.find(next) != um.end()) temp = um[next];
			if (um.find(cur) != um.end()) {
				for (int j = 0; j < um[cur].size(); j++) {
					bool isexist = false;
					for (int k = 0; k < temp.size(); k++) {
						if (temp[k].first == um[cur][j].first) {
							temp[k].second += count * um[cur][j].second;
							isexist = true; break;
						}
					}
					if (!isexist) temp.push_back({ um[cur][j].first, count * um[cur][j].second });
				}
			}
			else temp.push_back({ cur, count });
			um[next] = temp;
			degree[next] -= count;
			if (degree[next] == 0) q.push(next);
		}
	}
	sort(um[N].begin(), um[N].end());
	for (pair<int, int> part : um[N]) cout << part.first << " " << part.second << "\n";
	return 0;
}