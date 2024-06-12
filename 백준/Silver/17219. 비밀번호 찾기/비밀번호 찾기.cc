#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<string, string> um;
	for (int i = 0; i < n; i++) {
		string site, password; cin >> site >> password;
		um.insert({ site, password });
	}
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		cout << um[s] << "\n";
	}
	return 0;
}