#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K; cin >> K;
	vector<int> DP_A(K + 2);
	vector<int> DP_B(K + 2);
	DP_A[1] = 1, DP_B[1] = 0;
	for (int i = 2; i <= K + 1; i++) {
		DP_A[i] = DP_B[i - 1];
		DP_B[i] = DP_A[i - 1] + DP_B[i - 1];
	}
	cout << DP_A[K + 1] << " " << DP_B[K + 1];
	return 0;
}