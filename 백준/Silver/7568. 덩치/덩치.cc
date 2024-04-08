#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;
		p.push_back({ weight, height });
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (p[j].first > p[i].first && p[j].second > p[i].second) count++;
		}
		cout << count + 1 << " ";
	}
	return 0;
}