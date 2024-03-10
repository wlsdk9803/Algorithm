#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> um;
unordered_map<int, int> cnt;
vector<bool> visited;

void update_cnt(int i) {
	if (!visited[i]) {
		visited[i] = true;
		int point = um[i];
		cnt[point]--;
		if (cnt[point] == 0) update_cnt(point);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	visited.resize(N + 1);
	for (int i = 1; i <= N; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		um.insert({ i, num });
		cnt[num]++;
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) update_cnt(i);
	}
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] != 0) res.push_back(i);
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
	return 0;
}