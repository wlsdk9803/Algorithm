#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const int max_int = pow(10, 9);
	long long a, b; cin >> a >> b;
	queue<long long> q;
	unordered_map<long long, int> um;
	q.push(a);
	um.insert({ a, 1 });
	int res = -1;
	while (!q.empty()) {
		long long cur_num = q.front(); q.pop();
		if (cur_num == b) {
			res = um[cur_num];
			break;
		}
		long long next_num = 0;
		for (int i = 0; i < 2; i++) {
			if (i == 0) next_num = cur_num * 2;
			else if (i == 1) next_num = cur_num * 10 + 1;

			if (next_num > max_int) continue;
			else {
				if (um.find(next_num) == um.end()) um.insert({ next_num, um[cur_num] + 1 });
				else um[next_num] = min(um[next_num], um[cur_num] + 1);
			}
			q.push(next_num);
		}
	}
	cout << res;
	return 0;
}