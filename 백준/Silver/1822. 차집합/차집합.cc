#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	set<int> s;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		s.insert(num);
	}
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		if (s.find(num) != s.end()) s.erase(num);
	}
	if (s.size() == 0) cout << 0;
	else {
		cout << s.size() << "\n";
		for (int n : s) cout << n << " ";
	}
	return 0;
}