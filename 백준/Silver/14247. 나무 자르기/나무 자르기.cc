#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> trees(n);
	vector<int> grow(n);
	for (int i = 0; i < n; i++) cin >> trees[i].first;
	for (int i = 0; i < n; i++) cin >> trees[i].second;
	sort(trees.begin(), trees.end(), comp);

	long long res = 0;
	for (int i = 0; i < n; i++) res += trees[i].first + i * trees[i].second;
	cout << res;
	return 0;
}