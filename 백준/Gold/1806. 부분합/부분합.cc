#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, S; cin >> N >> S;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int len = 100001;
	int low = 0, high = 0;
	long long sum = v[0];
	while (low <= high && high < N) {
		if (sum < S) {
			if (high == N - 1) break;
			high++;
			sum += v[high];
		}
		else {
			len = min(len, high - low + 1);
			sum -= v[low];
			low++;
		}
	}
	if (len == 100001) cout << 0;
	else cout << len;
	return 0;
}