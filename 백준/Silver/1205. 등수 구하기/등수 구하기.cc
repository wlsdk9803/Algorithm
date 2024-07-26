#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, new_score, P; cin >> N >> new_score >> P;
	vector<long long> scores(N);
	for (int i = 0; i < N; i++) cin >> scores[i];
	if (N == P && scores[N - 1] >= new_score) {
		cout << -1;
		return 0;
	}
	reverse(scores.begin(), scores.end());
	int idx = upper_bound(scores.begin(), scores.end(), new_score) - scores.begin();
	cout << N - idx + 1;
    return 0;
}