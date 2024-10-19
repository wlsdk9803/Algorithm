#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int len, n; cin >> len >> n;
		int min_time = 0, max_time = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			int reverse_num = len - num;
			min_time = max(min_time, min(num, reverse_num));
			max_time = max(max_time, max(num, reverse_num));
		}
		cout << min_time << " " << max_time << "\n";
	}
	return 0;
}