#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(9, vector<int>(9));

bool check() {
    for (int i = 0; i < 9; i++) {
        vector<bool> row_visited(10);
        for (int j = 0; j < 9; j++) {
            if (row_visited[v[i][j]]) return false;
            row_visited[v[i][j]] = true;
        }
    }
    for (int j = 0; j < 9; j++) {
        vector<bool> col_visited(10);
        for (int i = 0; i < 9; i++) {
            if (col_visited[v[i][j]]) return false;
            col_visited[v[i][j]] = true;
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<bool> square_visited(10);
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (square_visited[v[i + row][j + col]]) return false;
                    square_visited[v[i + row][j + col]] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cin >> v[i][j];
        }
        string res = check() ? "CORRECT" : "INCORRECT";
        cout << "Case " << test << ": " << res << "\n";
    }
    return 0;
}
