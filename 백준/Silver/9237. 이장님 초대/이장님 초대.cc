#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<>());

	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, (i + 1) + v[i] + 1);
	}
	cout << res;
	return 0;
}