#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<int, bool> um;
	int res = n + m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		um.insert({ num, true });
	}
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (um.find(num) != um.end()) res -= 2;
	}
	cout << res;
	return 0;
}