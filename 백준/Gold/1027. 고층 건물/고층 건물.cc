#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> buildings;
double pre_tan = 0;
int cnt = 0;
bool ishigher = false;

void calculate(int i, int j) {
	if (!ishigher) { // 아직 더 크거나 같은 빌딩 안나온 상황에서
		if (buildings[i] > buildings[j]) { // 여전히 현 빌딩이 더 클 때
			double tan = (double)(buildings[i] - buildings[j]) / abs(i - j);
			if (pre_tan == 0 || tan < pre_tan) {
				cnt++;
				pre_tan = tan;
			}
		}
		else { // 더 크거나 같은 빌딩이 처음 나온 상황
			ishigher = true;
			pre_tan = (double)(buildings[j] - buildings[i]) / abs(i - j);
			cnt++;
		}
	}
	else { // 더 크거나 같은 빌딩이 나온 상황
		if (buildings[i] <= buildings[j]) {// 작은 빌딩은 패스
			double tan = (double)(buildings[j] - buildings[i]) / abs(i - j);
			if (tan > pre_tan) {
				cnt++;
				pre_tan = tan;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	buildings.resize(n);
	for (int i = 0; i < n; i++) cin >> buildings[i];
	int max_count = 0;
	for (int i = 0; i < n; i++) {
		pre_tan = 0, cnt = 0, ishigher = false;
		for (int j = i - 1; j >= 0; j--) calculate(i, j);

		pre_tan = 0, ishigher = false;
		for (int j = i + 1; j < n; j++) calculate(i, j);
		max_count = cnt > max_count ? cnt : max_count;
	}
	cout << max_count;
	return 0;
}