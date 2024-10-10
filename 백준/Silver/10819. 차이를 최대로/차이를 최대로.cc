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
	do {
		long long temp = 0;
		for (int i = 0; i < N - 1; i++) temp += abs(v[i] - v[i + 1]);
		res = res > temp ? res : temp;
	} while (next_permutation(v.begin(), v.end()));
	cout << res;
	return 0;
}