#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int n, m;

bool isValild(int row, int col) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<vector<char>> v(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++ ) cin >> v[i][j];
    }
    int white_power = 0, blue_power = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({ i, j });
            visited[i][j] = true;
            int temp = 1;
            while (!q.empty()) {
                int cur_row = q.front().first;
                int cur_col = q.front().second; q.pop();
                for (int k = 0; k < 4; k++) {
                    int next_row = cur_row + dy[k];
                    int next_col = cur_col + dx[k];
                    if (isValild(next_row, next_col) && !visited[next_row][next_col] && v[cur_row][cur_col] == v[next_row][next_col]) {
                        q.push({ next_row, next_col });
                        visited[next_row][next_col] = true;
                        temp++;
                    }
                }
            }
            if (v[i][j] == 'W') white_power += temp * temp;
            else blue_power += temp * temp;
        }
    }
    cout << white_power << " " << blue_power;
    return 0;
}