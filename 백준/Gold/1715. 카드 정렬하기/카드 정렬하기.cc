#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		pq.push(-num);
	}
	int count = 0;
	while (pq.size() >= 2) {
		int fir = pq.top(); pq.pop();
		int sec = pq.top(); pq.pop();
		count += -(fir + sec);
		pq.push(fir + sec);
	}
	cout << count;
	return 0;
}