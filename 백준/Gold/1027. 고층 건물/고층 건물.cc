#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> buildings(n);
	for (int i = 0; i < n; i++) cin >> buildings[i];

	int max_count = 0;
	for (int i = 0; i < n; i++) {
		double pre_tan = 0;
		int count = 0;
		bool ishigher = false;
		for (int j = i - 1; j >= 0; j--) {
			if (!ishigher) { // 아직 더 크거나 같은 빌딩 안나온 상황에서
				if (buildings[i] > buildings[j]) { // 여전히 현 빌딩이 더 클 때
					double tan = (double)(buildings[i] - buildings[j]) / (i - j);
					if (pre_tan == 0 || tan < pre_tan) {
						count++;
						pre_tan = tan;
					}
				}
				else { // 더 크거나 같은 빌딩이 처음 나온 상황
					ishigher = true;
					pre_tan = (double)(buildings[j] - buildings[i]) / (i - j);
					count++;
				}
			}
			else { // 더 크거나 같은 빌딩이 나온 상황
				if (buildings[i] > buildings[j]) continue; // 작은 빌딩은 패스
				double tan = (double)(buildings[j] - buildings[i]) / (i - j);
				if (tan > pre_tan) {
					count++;
					pre_tan = tan;
				}
			}
		}
		pre_tan = 0, ishigher = false;
		for (int j = i + 1; j < n; j++) {
			if (!ishigher) {
				if (buildings[i] > buildings[j]) {
					double tan = (double)(buildings[i] - buildings[j]) / (j - i);
					if (pre_tan == 0 || tan < pre_tan) {
						count++;
						pre_tan = tan;
					}
				}
				else {
					ishigher = true;
					pre_tan = (double)(buildings[j] - buildings[i]) / (j - i);
					count++;
				}
			}
			else {
				if (buildings[i] > buildings[j]) continue;
				double tan = (double)(buildings[j] - buildings[i]) / (j - i);
				if (tan > pre_tan) {
					count++;
					pre_tan = tan;
				}
			}
		}
		max_count = count > max_count ? count : max_count;
	}
	cout << max_count;
	return 0;
}