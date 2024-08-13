#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2; cin >> str1 >> str2;
	int n = str1.length(), m = str2.length();
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) v[i][j] = v[i - 1][j - 1] + 1;
			else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
		}
	}
	cout << v[n][m];
	if (v[n][m] != 0) {
		string res = "";
		int row = n, col = m;
		while (v[row][col] > 0) {
			if (v[row][col] == v[row - 1][col]) row--;
			else if (v[row][col] == v[row][col - 1]) col--;
			else {
				res += str1[row - 1];
				row--; col--;
			}
		}
		reverse(res.begin(), res.end());
		cout << "\n" << res;
	}
    return 0;
}