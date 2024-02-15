#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> str1, pair<int, string> str2) {
	if ((str1.first == str2.first) && (str1.second.length() == str2.second.length())) return str1.second < str2.second;
	if (str1.first == str2.first) return str1.second.length() > str2.second.length();
	return str1.first > str2.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<pair<int, string>> v;
	unordered_map<string, int> um;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		if (str.length() >= M) {
			if (um.find(str) == um.end()) um.insert({ str, 1 });
			else um[str]++;
		}
	}
	for (auto elem : um) v.push_back({ elem.second, elem.first });
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i].second << "\n";
	return 0;
}