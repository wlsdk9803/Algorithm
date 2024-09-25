#include <iostream>
#include <vector>

using namespace std;

int r, c;

int find_square_num(int gap, int srow, int scol, int prev_sum) {
	if (gap == 1) {
		if (r == srow) {
			if (c == scol) return prev_sum;
			else if (c == scol + gap) return prev_sum + 1;
		}
		else if (r == srow + gap) {
			if (c == scol) return prev_sum + 2;
			else if (c == scol + gap) return prev_sum + 3;
		}
	}
	else {
		pair<int, int> first_square_start = make_pair(srow, scol);
		pair<int, int> first_square_end = make_pair(srow + gap - 1, scol + gap - 1);

		pair<int, int> second_square_start = make_pair(srow, scol + gap);
		pair<int, int> second_square_end = make_pair(srow + gap - 1, scol + 2 * gap - 1);

		pair<int, int> third_square_start = make_pair(srow + gap, scol);
		pair<int, int> third_square_end = make_pair(srow + 2 * gap - 1, scol + gap - 1);

		pair<int, int> fourth_square_start = make_pair(srow + gap, scol + gap);
		pair<int, int> fourth_square_end = make_pair(srow + 2 * gap - 1, scol + 2 * gap - 1);

		if (r >= first_square_start.first && r <= first_square_end.first && c >= first_square_start.second && c <= first_square_end.second) {
			return find_square_num(gap / 2, srow, scol, prev_sum);
		}
		if (r >= second_square_start.first && r <= second_square_end.first && c >= second_square_start.second && c <= second_square_end.second) {
			return find_square_num(gap / 2, second_square_start.first, second_square_start.second, prev_sum + gap * gap);
		}
		if (r >= third_square_start.first && r <= third_square_end.first && c >= third_square_start.second && c <= third_square_end.second) {
			return find_square_num(gap / 2, third_square_start.first, third_square_start.second, prev_sum + gap * gap * 2);
		}
		if (r >= fourth_square_start.first && r <= fourth_square_end.first && c >= fourth_square_start.second && c <= fourth_square_end.second) {
			return find_square_num(gap / 2, fourth_square_start.first, fourth_square_start.second, prev_sum + gap * gap * 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N >> r >> c;
	cout << find_square_num(1 << N - 1, 0, 0, 0);
	return 0;
}