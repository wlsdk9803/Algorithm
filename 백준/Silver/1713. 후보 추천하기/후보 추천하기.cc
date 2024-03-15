#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> v;
	unordered_map<int, int> um;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (um.find(num) == um.end() || um[num] == 0) { //사진틀에 없는 학생이 들어왔을 때
			if (v.size() == n) { // 이미 사진 틀이 꽉 찬 경우
				priority_queue<pair<int, int>> pq;
				for (int j = 0; j < n; j++) pq.push({ -um[v[j]], -j });
				um[v[-pq.top().second]] = 0;
				v.erase(v.begin() - pq.top().second);
			}
			v.push_back(num);
			if (um.find(num) == um.end()) um.insert({ num, 1 });
			else if (um[num] == 0) um[num] = 1;
		}
		else um[num]++;
	}
	sort(v.begin(), v.end());
	for (auto stu : v) cout << stu << " ";
	return 0;
}