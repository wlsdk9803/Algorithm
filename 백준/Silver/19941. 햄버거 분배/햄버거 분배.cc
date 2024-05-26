#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<char> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] == 'P') {
			int left = i - K >= 0 ? i - K : 0;
			int right = i + K < N ? i + K : N - 1;
			for (int j = left; j <= right; j++) {
				if (v[j] == 'H') {
					res++; 
					v[j] = 'O'; // 먹은 건 O으로 표시
					break;
				}
			}
		}
	}
	cout << res;
	return 0;
}