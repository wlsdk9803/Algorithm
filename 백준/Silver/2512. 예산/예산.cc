#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	long long M; cin >> M;
	if (sum <= M) {
		cout << v[N - 1];
		return 0;
	}
	int count = N;
	long long res = M / count;
	for (int i = 0; i < N; i++) {
		if (v[i] >= res) {
			cout << res;
			return 0;
		}
		count--;
		M -= v[i];
		res = M / count;
	}
	return 0;
}