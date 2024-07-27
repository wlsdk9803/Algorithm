#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N; cin >> N;
		long long profit = 0;
		stack<int> s;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			s.push(num);
		}
		int standard = s.top(); s.pop();
		while (!s.empty()) {
			int cur = s.top(); s.pop();
			if (cur < standard) profit += (standard - cur);
			else if (cur > standard) standard = cur;
		}
		cout << profit << "\n";
	}
    return 0;
}