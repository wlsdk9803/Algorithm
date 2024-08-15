#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2; cin >> str1 >> str2;
	int n = str1.length(), m = str2.length();
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				res = v[i][j] > res ? v[i][j] : res;
			}
		}
	}
	cout << res;
    return 0;
}