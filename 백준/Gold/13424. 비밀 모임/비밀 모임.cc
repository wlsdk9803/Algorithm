#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N, M; cin >> N >> M;
		vector<vector<int>> adj(N + 1, vector<int>(N + 1, 100001));
		for (int i = 0; i <= N; i++) adj[i][i] = 0;
		for (int i = 0; i < M; i++) {
			int a, b, c; cin >> a >> b >> c;
			adj[a][b] = min(adj[a][b], c);
			adj[b][a] = min(adj[b][a], c);
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
			}
		}
		int K; cin >> K;
		vector<int> friends(K);
		for (int i = 0; i < K; i++) cin >> friends[i];

		int min_dist = 100001 * 100, room_num = -1;
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int f : friends) sum += adj[f][i];
			if (sum < min_dist) {
				min_dist = sum;
				room_num = i;
			}
		}
		cout << room_num << "\n";
	}
	return 0;
}