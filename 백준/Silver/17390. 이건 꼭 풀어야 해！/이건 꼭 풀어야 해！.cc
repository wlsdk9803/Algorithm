#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, Q; cin >> N >> Q;
	vector<int> A(N), sum(N + 1);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + A[i - 1];
	for (int i = 0; i < Q; i++) {
		int L, R; cin >> L >> R;
		cout << sum[R] - sum[L - 1] << "\n";
	}
	return 0;
}