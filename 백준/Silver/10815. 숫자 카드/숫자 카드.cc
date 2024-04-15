#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<int, int> cards;
	for (int i = 0; i < n; i++) {
		int card; cin >> card;
		cards.insert({ card, 1 });
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (cards.find(num) == cards.end()) cout << 0 << " ";
		else cout << 1 << " ";
	}
	return 0;
}