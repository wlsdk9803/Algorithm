#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> DP(N + 1);
	DP[0] = 1; DP[1] = 1; DP[2] = 2;
	for (int i = 3; i <= N; i++) DP[i] = DP[i - 1] + DP[i - 2];

	int res = 1, prev = 0;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		res *= DP[num - prev - 1];
		prev = num;
	}
	res *= DP[N - prev];
	cout << res;
	return 0;
}