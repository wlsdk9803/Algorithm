#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<pair<int, int>> v; // 끝 점 위치 저장
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>> res;
	res.push_back(v[0]);
	for (int i = 1; i < N; i++) {
		int res_back = res.back().second;
		int a = v[i].first;
		int b = v[i].second;
		if (a <= res_back && b > res_back) res[res.size() - 1].second = b;
		else if (a > res_back) res.push_back({ a, b });
	}
	int total_length = 0;
	for (int i = 0; i < res.size(); i++) total_length += res[i].second - res[i].first;
	cout << total_length;
	return 0;
}