#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	stack<int> s;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int sign; cin >> sign;
		switch (sign) {
		case 1:
			int x; cin >> x;
			s.push(x);
			break;
		case 2:
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << -1 << "\n";
			break;
		case 3:
			cout << s.size() << "\n";
			break;
		case 4:
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 5:
			if (!s.empty()) cout << s.top() << "\n";
			else cout << -1 << "\n";
			break;
		}
	}
	return 0;
}