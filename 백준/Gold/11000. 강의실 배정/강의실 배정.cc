#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<long long, long long>> v;
	for (int i = 0; i < n; i++) {
		long long a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	priority_queue<long long> pq;
	for (int i = 0; i < n; i++) {
		if (!pq.empty() && -pq.top() <= v[i].first) pq.pop();
		pq.push(-v[i].second);
	}
	cout << pq.size();
	return 0;
}