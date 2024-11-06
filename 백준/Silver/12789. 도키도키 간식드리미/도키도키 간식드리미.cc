#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		q.push(num);
	}
	bool isnice = true;
	int order = 1;
	stack<int> s;
	while (!q.empty() || !s.empty()) {
		bool flag = false;
		if (!q.empty() && q.front() == order) {
			q.pop(); order++;
			continue;
		}
		if (!s.empty() && s.top() == order) {
			s.pop(); order++;
			continue;
		}
		while (!q.empty()) {
			if (q.front() == order) {
				flag = true; break;
			}
			s.push(q.front()); q.pop();
		}
		if (!flag) {
			isnice = false;
			break;
		}
	}
	if (isnice) cout << "Nice";
	else cout << "Sad";
	return 0;
}