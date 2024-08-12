#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	long long res = 0;
	for (int max_idx = 0; max_idx < N; max_idx++) {
		vector<int> prev_v;
		vector<int> next_v;
		for (int i = 0; i < max_idx; i++) {
			if (A[i] == A[max_idx]) continue;
			if (prev_v.empty() || A[i] > prev_v.back()) prev_v.push_back(A[i]);
			else {
				int index = lower_bound(prev_v.begin(), prev_v.end(), A[i]) - prev_v.begin();
				prev_v[index] = A[i];
			}
		}
		vector<int> temp(A.begin() + max_idx, A.end());
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			if (next_v.empty() || temp[i] > next_v.back()) next_v.push_back(temp[i]);
			else {
				int index = lower_bound(next_v.begin(), next_v.end(), temp[i]) - next_v.begin();
				next_v[index] = temp[i];
			}
		}
		res = res > prev_v.size() + next_v.size() ? res : prev_v.size() + next_v.size();
	}
	cout << res;
    return 0;
}