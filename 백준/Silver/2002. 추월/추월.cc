#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<string, int> car;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		car[str] = i;
	}
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		v[i] = car[str];
	}
	int over_car = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (v[i] > v[j]) {
				over_car++; break;
			}
		}
	}
	cout << over_car;
	return 0;
}