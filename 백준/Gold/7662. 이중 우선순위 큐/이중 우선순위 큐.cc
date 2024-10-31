#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int k; cin >> k;
		priority_queue<pair<long long, int>> max_pq, min_pq;
		vector<bool> deleted(k);
		for (int i = 0; i < k; i++) {
			char type; cin >> type;
			long long num; cin >> num;
			if (type == 'I') {
				max_pq.push({ num, i });
				min_pq.push({ -num, i });
			}
			else if (type == 'D') {
				if (num == 1 && !max_pq.empty()) {
					while (!max_pq.empty() && deleted[max_pq.top().second]) max_pq.pop();
					if (!max_pq.empty()) {
						deleted[max_pq.top().second] = true;
						max_pq.pop();
					}
				}
				if (num == -1 && !min_pq.empty()) {
					while (!min_pq.empty() && deleted[min_pq.top().second]) min_pq.pop();
					if (!min_pq.empty()) {
						deleted[min_pq.top().second] = true;
						min_pq.pop();
					}
				}
			}
		}
		while (!max_pq.empty() && deleted[max_pq.top().second]) max_pq.pop();
		while (!min_pq.empty() && deleted[min_pq.top().second]) min_pq.pop();
		if (max_pq.empty() && min_pq.empty()) cout << "EMPTY\n";
		else cout << max_pq.top().first << " " << -min_pq.top().first << "\n";
	}
	return 0;
}