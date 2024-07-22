#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    unordered_map<int, int> ladder;
    unordered_map<int, int> snake;

    for (int i = 0; i < n + m; i++) {
        int a, b; cin >> a >> b;
        if (i < n) ladder.insert({ a, b });
        else snake.insert({ a,b });
    }

    vector<bool> visited(101);
    vector<int> dist(101, 1 << 30 - 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == 100) break;
        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next >= 1 && next <= 100 && !visited[next] && dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                visited[next] = true;
                if (ladder.find(next) != ladder.end() || snake.find(next) != snake.end()) {
                    if(ladder.find(next) != ladder.end()) next = ladder[next];
                    if(snake.find(next) != snake.end()) next = snake[next];
                    if (!visited[next] && dist[next] > dist[cur] + 1) {
                        dist[next] = dist[cur] + 1;
                        visited[next] = true;
                        q.push(next);
                    }
                }
                else q.push(next);

            }
        }
    }
    cout << dist[100];
    return 0;
}