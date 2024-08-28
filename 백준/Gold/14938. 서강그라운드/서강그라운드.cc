#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, r; cin >> n >> m >> r;
	vector<int> v(n + 1);
	vector<vector<int>> edge(n + 1, vector<int>(n + 1, 16));
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 0; i <= n; i++) edge[i][i] = 0;
	for (int i = 0; i < r; i++) {
		int a, b, l; cin >> a >> b >> l;
		edge[a][b] = min(edge[a][b], l);
		edge[b][a] = min(edge[b][a], l);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (edge[i][j] <= m) sum += v[j];
		}
		res = max(res, sum);
	}
	cout << res;
	return 0;
}