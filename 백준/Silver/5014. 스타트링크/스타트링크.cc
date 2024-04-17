#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

bool isValid(int pos, int F) {
	return pos > 0 && pos <= F;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
	vector<int> dist(F + 1, INT_MAX);
	vector<bool> visited(F + 1);
	queue<int> q;
	q.push(S);
	visited[S] = true;
	dist[S] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == G) break;
		for (int i = 0; i < 2; i++) {
			int next;
			if (i == 0) next = cur + U;
			else next = cur - D;
			if (isValid(next, F) && !visited[next]) {
				dist[next] = min(dist[next], dist[cur] + 1);
				q.push(next);
				visited[next] = true;
			}
		}
	}
	if (dist[G] != INT_MAX) cout << dist[G];
	else cout << "use the stairs";
	return 0;
}