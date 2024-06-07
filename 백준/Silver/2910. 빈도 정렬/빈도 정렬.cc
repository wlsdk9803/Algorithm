#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first != b.second.first) return a.second.first > b.second.first;
	else return a.second.second < b.second.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, C; cin >> N >> C;
	unordered_map<int, pair<int, int>> um; // count, order
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (um.find(num) == um.end()) {
			um.insert({ num, {1, i} });
			temp.push_back(num);
		}
		else um[num].first++;
	}
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < temp.size(); i++) v.push_back({ temp[i], {um[temp[i]].first, um[temp[i]].second} });
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second.first; j++) cout << v[i].first << " ";
	}
	return 0;
}