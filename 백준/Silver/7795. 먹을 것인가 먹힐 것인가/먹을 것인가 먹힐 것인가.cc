#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N, M; cin >> N >> M;
		vector<int> va(N);
		vector<int> vb(M);
		for (int i = 0; i < N; i++) cin >> va[i];
		for (int i = 0; i < M; i++) cin >> vb[i];
		sort(va.begin(), va.end(), greater<>());
		sort(vb.begin(), vb.end());

		int res = 0;
		for (int i = 0; i < N; i++){
			res += lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
		}
		cout << res << "\n";
	}
	return 0;
}