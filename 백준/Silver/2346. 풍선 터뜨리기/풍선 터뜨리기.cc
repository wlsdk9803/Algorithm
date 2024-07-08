#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	deque<pair<int, int>> dq;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		dq.push_back({ i, num });
	}
	cout << dq.front().first << " ";
	pair<int, int> cur = dq.front(); dq.pop_front();
	pair<int, int> next;
	while (!dq.empty()) {
		for (int i = 0; i < abs(cur.second); i++) {
			if (cur.second > 0) {
				next = dq.front(); dq.pop_front();
				if (i < abs(cur.second) - 1) dq.push_back(next);
			}
			else {
				next = dq.back(); dq.pop_back();
				if (i < abs(cur.second) - 1) dq.push_front(next);
			}
		}
		cout << next.first << " ";
		cur = next;
	}
	return 0;
}