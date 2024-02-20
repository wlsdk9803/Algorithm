#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#define LL long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		string comd; cin >> comd;
		if (comd == "QUIT") return 0;

		vector<pair<string, LL>> commands;
		if (comd != "NUM" && comd != "END") commands.push_back({comd,0});
		else if (comd == "NUM") {
			LL number; cin >> number;
			commands.push_back({ comd, number });
		}
		if (comd != "END") {
			while (true) {
				string command; cin >> command;
				if (command == "END") break;
				if (command != "NUM") commands.push_back({ command,0 });
				else {
					LL number; cin >> number;
					commands.push_back({ command, number });
				}
			}
		}
		int count; cin >> count;
		for (int i = 0; i < count; i++) {
			LL input; cin >> input;
			stack<LL> s;
			s.push(input);
			bool error = false;
			for (int j = 0; j < commands.size(); j++) {
				string cur = commands[j].first;
				if (cur == "NUM") {
					LL x = commands[j].second;
					s.push(x);
				}
				else if (cur == "POP") {
					if (s.empty()) {
						error = true;  break;
					}
					else s.pop();
				}
				else if (cur == "INV") {
					if (s.empty()) {
						error = true; break;
					}
					else {
						LL top = s.top(); s.pop();
						s.push(-top);
					}
				}
				else if (cur == "DUP") {
					if (s.empty()) {
						error = true; break;
					}
					else {
						LL top = s.top();
						s.push(top);
					}
				}
				else if (cur == "SWP") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					s.push(fir); s.push(sec);
				}
				else if (cur == "ADD") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					LL res = fir + sec;
					if (abs(res) > pow(10, 9)) {
						error = true; break;
					}
					s.push(fir + sec);
				}
				else if (cur == "SUB") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					LL res = sec - fir;
					if (abs(res) > pow(10, 9)) {
						error = true; break;
					}
					s.push(sec - fir);
				}
				else if (cur == "MUL") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					LL res = fir * sec;
					if (abs(res) > pow(10, 9)) {
						error = true; break;
					}
					s.push(fir * sec);
				}
				else if (cur == "DIV") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					if (fir == 0) {
						error = true; break;
					}
					LL res = sec / fir;
					if ((fir < 0 && sec > 0) || (fir > 0 && sec < 0)) {
						res = -(abs(sec / fir));
					}
					else if (res < 0) res *= -1;
					s.push(res);
				}
				else if (cur == "MOD") {
					if (s.size() < 2) {
						error = true; break;
					}
					LL fir = s.top(); s.pop();
					LL sec = s.top(); s.pop();
					if (fir == 0) {
						error = true; break;
					}
					LL res = sec % fir;
					if (fir < 0 && sec > 0) res = abs(sec % fir);
					else if (fir > 0 || sec < 0) res = -abs(sec % fir);
					s.push(sec % fir);
				}
			}
			if (error || s.size() != 1) cout << "ERROR\n";
			if (!error && s.size() == 1) cout << s.top() << "\n";
		}
		cout << "\n";
	}
	return 0;
}