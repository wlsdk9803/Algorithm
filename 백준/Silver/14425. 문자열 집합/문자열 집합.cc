#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<string, bool> um;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		um.insert({ str, true });
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		string str; cin >> str;
		if (um.find(str) != um.end()) res++;
	}
	cout << res;
	return 0;
}