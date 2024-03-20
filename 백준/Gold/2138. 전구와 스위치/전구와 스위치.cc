#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> origin(n);
	vector<int> tobe(n);
	for (int i = 0; i < n; i++) {
		char num; cin >> num;
		origin[i] = num - '0';
	}
	for (int i = 0; i < n; i++) {
		char num; cin >> num;
		tobe[i] = num - '0';
	}
	int result = INT_MAX;
	for (int idx = 0; idx < 2; idx++) {
		// idx가 0이면 0번째 스위치를 누른 경우
		// idx가 1이면 0번째 스위치를 누르지 않은 경우
		int sum = 0;
		vector<int> temp = origin;
		if (idx == 0) {
			temp[0] = -(temp[0] - 1); // 반전시킬 땐 1을 빼고 -1을 곱하면 됨
			temp[1] = -(temp[1] - 1);
			sum++;
		}
		for (int i = 0; i < n - 2; i++) {
			if (temp[i] != tobe[i]) { // i번째 스위치가 다르면 i+1번 스위치를 누른다
				temp[i] = -(temp[i] - 1);
				temp[i + 1] = -(temp[i + 1] - 1);
				temp[i + 2] = -(temp[i + 2] - 1);
				sum++;
			}
		}
		if (temp[n - 2] != tobe[n - 2]) { // 마지막 스위치를 누르는 경우
			temp[n - 2] = -(temp[n - 2] - 1);
			temp[n - 1] = -(temp[n - 1] - 1);
			sum++;
		}
		if (temp[n - 1] == tobe[n - 1]) result = min(result, sum);
	}
	if (result == INT_MAX) cout << -1;
	else cout << result;
	return 0;
}