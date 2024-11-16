#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

void reverse_coin(int row, int col) {
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) v[i][j] = !v[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			v[i].push_back(c - '0');
		}
	}
	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (v[i][j] == 1) {
				reverse_coin(i, j);
				count++;
			}
		}
	}
	cout << count;
	return 0;
}