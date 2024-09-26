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
	int row = 0, col = 0;
	for (int i = 0; i < N; i++) {
		int temp_row = 0;
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 'X') temp_row = 0;
			else if (++temp_row == 2) row++;
		}
	}
	for (int j = 0; j < N; j++) {
		int temp_col = 0;
		for (int i = 0; i < N; i++) {
			if (v[i][j] == 'X') temp_col = 0;
			else if (++temp_col == 2) col++;
		}
	}
	cout << row << " " << col;
	return 0;
}