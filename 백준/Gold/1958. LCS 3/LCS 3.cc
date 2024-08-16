#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2, str3; cin >> str1 >> str2 >> str3;
	int n = str1.length(), m = str2.length(), r = str3.length();
	vector<vector<int>> temp(m + 1, vector<int>(r + 1));
	vector<vector<vector<int>>> v(n + 1, temp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= r; k++) {
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) v[i][j][k] = v[i - 1][j - 1][k - 1] + 1;
				else v[i][j][k] = max(max(v[i - 1][j][k], v[i][j - 1][k]), v[i][j][k - 1]);
			}
		}
	}
	cout << v[n][m][r];
    return 0;
}