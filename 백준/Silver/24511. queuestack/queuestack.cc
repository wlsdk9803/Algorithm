#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> isstack(N);
	deque<int> dq;
	for (int i = 0; i < N; i++) cin >> isstack[i];
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (!isstack[i]) dq.push_back(num);
	}
	int M; cin >> M;
	for (int test = 0; test < M; test++) {
		int num; cin >> num;
		dq.push_front(num);
		cout << dq.back() << " ";
		dq.pop_back();
	}
	return 0;
}