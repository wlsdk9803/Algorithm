#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>> v1, vector<vector<long long>> v2) {
	int n = v1.size();
	vector<vector<long long>> result(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) result[i][j] += v1[i][k] * v2[k][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] %= 1000;
		}
	}
	return result;
}

vector<vector<long long>> square(vector<vector<long long>> A, long long B) {
	if (B == 0 || B == 1) return A;
	vector<vector<long long>> temp = square(A, B / 2);
	if (B % 2 == 0) return multiply(temp, temp);
	else return multiply(A, multiply(temp, temp));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; long long B;
	cin >> N >> B;
	vector<vector<long long>> A(N, vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	vector<vector<long long>> res = square(A, B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << res[i][j] % 1000 << " ";
		cout << "\n";
	}
	return 0;
}