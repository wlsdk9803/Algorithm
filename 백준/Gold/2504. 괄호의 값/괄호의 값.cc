#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	stack<int> s;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		int cur = 0;
		bool isValid = true;
		switch (c) {
		case '(':
			s.push(-1);
			break;
		case '[':
			s.push(-2);
			break;
		case ')':
			while (!s.empty() && s.top() != -1 && s.top() != -2) {
				cur += s.top(); s.pop();
			}
			if (s.empty() || s.top() == -2) isValid = false;
			else {
				if (cur == 0) cur += 2;
				else cur *= 2;
				s.pop();
				s.push(cur);
			}
			break;
		case ']':
			while (!s.empty() && s.top() != -1 && s.top() != -2) {
				cur += s.top(); s.pop();
			}
			if (s.empty() || s.top() == -1) isValid = false;
			else {
				if (cur == 0) cur += 3;
				else cur *= 3;
				s.pop();
				s.push(cur);
			}
			break;
		}
		if (!isValid) {
			cout << 0; return 0;
		}
	}
	int res = 0;
	while (!s.empty()) {
		if (s.top() == -1 || s.top() == -2) {
			cout << 0; return 0;
		}
		res += s.top(); s.pop();
	}
	cout << res;
	return 0;
}