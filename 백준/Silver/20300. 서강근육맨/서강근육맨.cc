#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	int end_num = N % 2 == 0 ? N : N - 1;
	long long min_M = N % 2 == 0 ? 0 : v[N - 1];
	for (int i = 0; i < end_num / 2; i++) min_M = max(v[i] + v[end_num - 1 - i], min_M);
	cout << min_M;
	return 0;
}