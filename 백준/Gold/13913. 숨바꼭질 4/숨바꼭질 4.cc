#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxnum = 100001;
bool visited[maxnum] = { false };

vector<int> path;

int bfs(int start, int end) {
	int parent[maxnum];
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int start_to_cur = q.front().second;
		q.pop();
		if (cur == end) {
			path.push_back(cur);
			int idx = cur;
			while (idx != start) {
				path.push_back(parent[idx]);
				idx = parent[idx];
			}
			return start_to_cur;
		}

		for (int i = 0; i < 3; i++) {
			int next, start_to_next;
			switch (i) {
			case(0):
				next = cur - 1;
				start_to_next = start_to_cur + 1;
				break;
			case(1):
				next = cur + 1;
				start_to_next = start_to_cur + 1;
				break;
			case(2):
				next = cur * 2;
				start_to_next = start_to_cur + 1;
				break;
			default:
				break;
			}
			if (next >= 0 && next < maxnum && !visited[next]) {
				parent[next] = cur;
				visited[next] = true;
				q.push({ next, start_to_next });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	cout << bfs(N, K) << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	return 0;
}