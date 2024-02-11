#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<int> res(n);
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && v[i] >= v[s.top()]) {
			res[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) cout << res[i] << " ";
	return 0;
}