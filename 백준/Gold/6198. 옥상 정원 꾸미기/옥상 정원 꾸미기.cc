#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	const int max_height = 1000000001;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	v.push_back(max_height);

	stack<int> s;
	vector<int> count(N + 1);
	for (int i = 0; i <= N; i++) {
		while (!s.empty() && v[s.top()] <= v[i]) {
			count[s.top()] = i - s.top() - 1;
			s.pop();
		}
		s.push(i);
	}
	long long res = 0;
	for (int i = 0; i < N; i++) res += count[i];
	cout << res;
	return 0;
}