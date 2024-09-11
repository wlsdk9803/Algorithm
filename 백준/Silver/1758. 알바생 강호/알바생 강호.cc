#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<>());

	long long res = 0;
	for (long long i = 0; i < N; i++) {
		long long tip = v[i] - i;
		res += tip < 0 ? 0 : tip;
	}
	cout << res;
	return 0;
}