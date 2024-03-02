#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++) parent.push_back(i);
	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back({ c, {a,b} }); //비용, 노드 두개
	}
	sort(edge.begin(), edge.end());
	long long sum = 0;
	int count = 0;
	for (int i = 0; i < edge.size(); i++) {
		if (find(edge[i].second.first) == find(edge[i].second.second)) continue;
		merge(edge[i].second.first, edge[i].second.second);
		sum += edge[i].first;
		count++;
		if (count == N - 1) {
			sum -= edge[i].first; break;
		}
	}
	cout << sum;
	return 0;
}