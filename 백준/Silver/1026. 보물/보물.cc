#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	long long sum = 0;
	for (int i = 0; i < n; i++) sum += A[i] * B[i];
	cout << sum;
	return 0;
}