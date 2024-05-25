#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	if (a.second.first != b.second.first) return a.second.first < b.second.first;
	if (a.second.second != b.second.second) return a.second.second > b.second.second;
	return a.first.first < b.first.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<pair<string, int>, pair<int, int>>> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < N; i++) cout << v[i].first.first << "\n";
	return 0;
}