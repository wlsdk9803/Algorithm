#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isValid(int row, int col) {
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<int>> v(8, vector<int>(8));
	string king, stone; cin >> king >> stone;
	pair<int, int> k_pos = make_pair(8 - (king[1] - '0'), king[0] - 'A');
	pair<int, int> s_pos = make_pair(8 - (stone[1] - '0'), stone[0] - 'A');
	int N; cin >> N;
	for (int idx = 0; idx < N; idx++) {
		string dir; cin >> dir;
		if (dir[0] == 'R') {
			int nrow = k_pos.first;
			int ncol = k_pos.second + 1;
			if (dir.length() == 2 && dir[1] == 'T') nrow--;
			else if (dir.length() == 2 && dir[1] == 'B') nrow++;
			if (isValid(nrow, ncol)) {
				if (s_pos == make_pair(nrow, ncol)) {
					if (isValid(s_pos.first + (nrow - k_pos.first), s_pos.second + 1)) {
						s_pos.second++;
						s_pos.first += (nrow - k_pos.first);
					}
					else continue;
				}
				k_pos = make_pair(nrow, ncol);
			}
		}
		else if (dir[0] == 'L') {
			int nrow = k_pos.first;
			int ncol = k_pos.second - 1;
			if (dir.length() == 2 && dir[1] == 'T') nrow--;
			else if (dir.length() == 2 && dir[1] == 'B') nrow++;
			if (isValid(nrow, ncol)) {
				if (s_pos == make_pair(nrow, ncol)) {
					if (isValid(s_pos.first + (nrow - k_pos.first), s_pos.second - 1)) {
						s_pos.second--;
						s_pos.first += (nrow - k_pos.first);
					}
					else continue;
				}
				k_pos = make_pair(nrow, ncol);
			}
		}
		else if (dir == "B") {
			if (isValid(k_pos.first + 1, k_pos.second)) {
				if (s_pos == make_pair(k_pos.first + 1, k_pos.second)) {
					if (isValid(s_pos.first + 1, s_pos.second)) s_pos.first++;
					else continue;
				}
				k_pos.first++;
			}
		}
		else if (dir == "T") {
			if (isValid(k_pos.first - 1, k_pos.second)) {
				if (s_pos == make_pair(k_pos.first - 1, k_pos.second)) {
					if (isValid(s_pos.first - 1, s_pos.second)) s_pos.first--;
					else continue;
				}
				k_pos.first--;
			}
		}
	}
	cout << (char)(k_pos.second + 'A') << 8 - k_pos.first << "\n";
	cout << (char)(s_pos.second + 'A') << 8 - s_pos.first;
	return 0;
}