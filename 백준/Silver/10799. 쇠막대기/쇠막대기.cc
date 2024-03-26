#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string cmd; cin >> cmd;
	stack<int> s;
	int sum = 0;
	bool open = false;
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] == '(') {
			sum++;
			s.push(1); // 아무거나 넣어도 상관없음
			open = true;
		}
		else {
			if (open) {
				sum--;
				s.pop();
				sum += s.size();
			}
			else s.pop();
			open = false;
		}
	}
	cout << sum;
	return 0;
}