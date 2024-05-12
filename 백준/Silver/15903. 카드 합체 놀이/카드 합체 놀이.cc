#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	priority_queue<long long> pq;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		pq.push(-num);
	}
	for (int i = 0; i < m; i++) {
		long long fir = -pq.top(); pq.pop();
		long long sec = -pq.top(); pq.pop();
		long long sum = fir + sec;
		for (int j = 0; j < 2; j++) pq.push(-sum);
	}
	long long res = 0;
	while (!pq.empty()) {
		res += -pq.top(); pq.pop();
	}
	cout << res;
	return 0;
}