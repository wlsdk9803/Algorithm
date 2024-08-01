#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int arr[1001] = { 0, };
	int DP[1001] = { 0, };
	int answer = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + 1);
		}
		answer = max(answer, DP[i]);
	}
	cout << answer;
	return 0;
}