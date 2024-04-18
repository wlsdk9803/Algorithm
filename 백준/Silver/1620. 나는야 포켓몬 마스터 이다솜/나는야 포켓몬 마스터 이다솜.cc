#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map<string, int> pockets_name;
	unordered_map<int, string> pockets_order;
	for (int i = 1; i <= n; i++) {
		string pocket; cin >> pocket;
		pockets_name.insert({ pocket, i });
		pockets_order.insert({ i, pocket });
	}
	for (int i = 0; i < m; i++) {
		string str; cin >> str;
		if ('1' <= str[0] && str[0] <= '9') {
			int order = stoi(str);
			cout << pockets_order[order] << "\n";
		}
		else cout << pockets_name[str] << "\n";
	}
	return 0;
}