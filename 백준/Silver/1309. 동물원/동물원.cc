#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(3));
	v[0][0] = 1; v[0][1] = 1; v[0][2] = 1;
	for (int i = 1; i < N; i++) {
		v[i][0] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2]) % 9901;
		v[i][1] = (v[i - 1][0] + v[i - 1][2]) % 9901;
		v[i][2] = (v[i - 1][0] + v[i - 1][1]) % 9901;
	}
	cout << (v[N - 1][0] + v[N - 1][1] + v[N - 1][2]) % 9901;
	return 0;
}