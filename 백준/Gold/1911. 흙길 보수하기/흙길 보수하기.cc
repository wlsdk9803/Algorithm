#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, L; cin >> N >> L;
	int count = 0, p = -1;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int start, end; cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		int start = v[i].first;
		int end = v[i].second;
		if (p < start) p = start;
		if (p >= end) continue;

		int width = end - p; // 웅덩이 길이
		int q = width / L;
		count += q;
		if (q * L < width) {
			count++;
			p += (q + 1) * L;
		}
	}
	cout << count;
	return 0;
}