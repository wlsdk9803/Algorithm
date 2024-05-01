#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<char>> v(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> v[i][j];
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		int count = 0;
		vector<bool> visited(N);
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 'Y' || v[j][i] == 'Y') {
				if (!visited[j]) {
					count++;
					visited[j] = true;
				}
				for (int k = 0; k < N; k++) {
					if (k == i) continue;
					if ((v[j][k] == 'Y' || v[k][j] == 'Y') && !visited[k]) {
						count++;
						visited[k] = true;
					}
				}
			}
		}
		res = res > count ? res : count;
	}
	cout << res;
	return 0;
}