#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dist(n, 1001);
    for (int i = 0; i < n; i++) cin >> v[i];

    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == n - 1) break;
        for (int i = 1; i <= v[cur]; i++) {
            int next = cur + i;
            if (next < n && dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    if (dist[n - 1] == 1001) cout << -1;
    else cout << dist[n - 1];
    return 0;
}