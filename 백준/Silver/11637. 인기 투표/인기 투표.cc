#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int n; cin >> n;
		int sum = 0;
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++) {
			int num; cin >> num;
			sum += num;
			pq.push({ num, i });
		}
		pair<int, int> fir = pq.top(); pq.pop();
		pair<int, int> sec = pq.top();
		if (fir.first == sec.first) cout << "no winner\n";
		else if (fir.first <= sum / 2) cout << "minority winner " << fir.second << "\n";
		else cout << "majority winner "<<fir.second<<"\n";
	}
	return 0;
}