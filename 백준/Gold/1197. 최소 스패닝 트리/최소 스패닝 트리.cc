#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_parent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find_parent(parent[a]);
}

void merge(int a, int b) {
	parent[find_parent(b)] = find_parent(a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int V, E; cin >> V >> E;
	for (int i = 0; i <= V; i++) parent.push_back(i);
	vector<pair<long long, pair<int, int>>> edge;
	for (int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		edge.push_back({ w, {u, v} });
	}
	sort(edge.begin(), edge.end());
	long long sum = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (find_parent(edge[i].second.first) == find_parent(edge[i].second.second)) continue;
		merge(edge[i].second.first, edge[i].second.second);
		sum += edge[i].first;
	}
	cout << sum;
    return 0;
}