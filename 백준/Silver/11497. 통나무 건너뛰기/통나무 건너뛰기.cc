#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N; cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v.begin(), v.end());

		vector<int> temp(N);
		int j = 0;
		for (int i = 0; i < N - 1; i += 2) {
			int fir = v[i], sec = v[i + 1];
			temp[j] = fir;
			temp[N - 1 - j] = sec;
			j++;
		}
		if (N % 2 == 1) temp[N / 2] = v[N - 1];

		int max_diff = abs(temp[0] - temp[N - 1]);
		for (int i = 0; i < N - 1; i++) max_diff = max(max_diff, abs(temp[i] - temp[i + 1]));
		cout << max_diff << "\n";
	}
	return 0;
}