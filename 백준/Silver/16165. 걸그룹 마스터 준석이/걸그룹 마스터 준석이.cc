#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	unordered_map<string, vector<string>> um1;
	unordered_map<string, string> um2;
	for (int i = 0; i < N; i++) {
		string group; cin >> group;
		int num; cin >> num;
		vector<string> temp(num);
		for (int j = 0; j < num; j++) {
			cin >> temp[j];
			um2.insert({ temp[j], group });
		}
		sort(temp.begin(), temp.end());
		um1.insert({ group, temp });
	}
	for (int i = 0; i < M; i++) {
		string str; int type;
		cin >> str >> type;
		if (type) cout << um2[str] << "\n";
		else {
			for (string member : um1[str]) cout << member << "\n";
		}
	}
	return 0;
}
