#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	vector<int> heights(N);
	for (int i = 0; i < N; i++) cin >> heights[i];

	vector<int> diff;
	for (int i = 1; i < N; i++) diff.push_back(heights[i] - heights[i - 1]);
	sort(diff.begin(), diff.end());

	long long cost = 0;
	for (int i = 0; i < N - K; i++) cost += diff[i];
	cout << cost;
	return 0;
}