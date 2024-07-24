#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	const int dot_range = 100000 + 1;
	vector<int> time(dot_range, INT_MAX);
	queue<int> q;
	q.push(N);
	time[N] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0) next = cur - 1;
			else if (i == 1) next = cur + 1;
			else next = 2 * cur;
			if (next >= 0 && next < dot_range) {
				if ((i == 0 || i == 1) && time[next] > time[cur] + 1) {
					time[next] = time[cur] + 1;
					q.push(next);
				}
				else if (i == 2 && time[next] > time[cur]) {
					time[next] = time[cur];
					q.push(next);
				}
			}
		}
	}
	cout << time[K];
    return 0;
}