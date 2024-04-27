#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, L; cin >> K >> L;
	unordered_map<string, int> um_id;
	unordered_map<int, string> um_order;
	for (int i = 0; i < L; i++) {
		string id; cin >> id;
		if (um_id.find(id) == um_id.end()) um_id.insert({ id, i });
		else um_id[id] = i;
		um_order.insert({ i, id });
	}
	int count = 0;
	for (int i = 0; i < L; i++) {
		if (i == um_id[um_order[i]]) {
			cout << um_order[i] << "\n";
			count++;
		}
		if (count == K) break;
	}
	return 0;
}