#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	int count = 0;
	deque<int> dq;
	for (int i = 1; i <= N; i++) dq.push_back(i);
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		int dist = find(dq.begin(), dq.end(), num) - dq.begin();
		bool isleft = dist <= dq.size() / 2 ? true : false;
		if (isleft) {
			for (int j = 0; j < dist; j++) {
				int f = dq.front(); dq.pop_front();
				dq.push_back(f);
				count++;
			}
		}
		else {
			for (int j = dq.size(); j > dist; j--) {
				int b = dq.back(); dq.pop_back();
				dq.push_front(b);
				count++;
			}
		}
		dq.pop_front();
	}
	cout << count;
	return 0;
}