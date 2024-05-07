#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	long long res = 0;
	for (int i = 0; i < N; i++) {
		res += abs((i + 1) - v[i]);
	}
	cout << res;
	return 0;
}