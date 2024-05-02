#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N; cin >> N;
		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

		sort(v.begin(), v.end());
		int count = 1;
		int sec_best = v[0].second;
		for (int i = 1; i < N; i++) {
			if (v[i].second < sec_best) {
				count++;
				sec_best = v[i].second;
			}
		}
		cout << count << "\n";
	}
	return 0;
}