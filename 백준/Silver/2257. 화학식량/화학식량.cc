#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	unordered_map<char, int> um = { { 'H', 1 }, { 'C', 12 }, { 'O', 16 } };
	stack<int> s;
	int res = 0;
	for (char c : str) {
		if (c == '(') s.push(0);
		else if (c == ')') {
			int temp_total = 0;
			while (!s.empty() && s.top() != 0) {
				temp_total += s.top();
				s.pop();
			}
			s.pop();
			s.push(temp_total);
		}
		else if (c >= '2' && c <= '9') {
			int top = s.top(); s.pop();
			s.push(top * (c - '0'));
		}
		else s.push(um[c]);
	}
	while (!s.empty()) {
		res += s.top(); s.pop();
	}
	cout << res;
	return 0;
}