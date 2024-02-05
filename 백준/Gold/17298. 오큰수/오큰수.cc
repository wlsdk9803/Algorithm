#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	vector<int> res(N, -1);
	for (int i = 0; i < N; i++) cin >> v[i];
	
	stack<int> s;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			res[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < N; i++) cout << res[i] << " ";
	return 0;
}