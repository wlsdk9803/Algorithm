#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	unordered_map<long long, int> um;
	vector<long long> v;
	long long max_num = 0;
	for (int i = 0; i < N; i++) {
		long long card; cin >> card;
		if (um.find(card) == um.end()) {
			um.insert({ card, 1 });
			v.push_back(card);
		}
		else um[card]++;
		max_num = max_num > um[card] ? max_num : um[card];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (um[v[i]] == max_num) {
			cout << v[i];
			break;
		}
	}
	return 0;
}