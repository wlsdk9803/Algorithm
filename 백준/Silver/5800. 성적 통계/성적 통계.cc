#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K; cin >> K;
	for (int i = 1; i <= K; i++) {
		int N; cin >> N;
		vector<int> v(N);
		for (int j = 0; j < N; j++) cin >> v[j];
		sort(v.begin(), v.end(), greater<>());
		int max_gap = 0;
		for (int j = 0; j < N - 1; j++) {
			max_gap = max(max_gap, v[j] - v[j + 1]);
		}
		cout << "Class " << i << "\n";
		cout << "Max " << v[0] << ", Min " << v[N - 1] << ", Largest gap " << max_gap << "\n";
	}
	return 0;
}