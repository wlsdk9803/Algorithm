#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int res = 0;
	for (int test = 0; test < N; test++) {
		string str; cin >> str;
		stack<char> s;
		for (char c : str) {
			if (s.empty() || s.top() != c) s.push(c);
			else s.pop();
		}
		if (!s.empty()) continue;
		res++;
	}
	cout << res;
	return 0;
}