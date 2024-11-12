#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	set<int> s;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum += v[i];
		s.insert(v[i]);
	}
	sort(v.begin(), v.end());
	int avg = round(sum / (double)N);
	avg = avg == -0 ? 0 : avg;
	cout << avg << "\n" << v[N / 2] << "\n";

	unordered_map<int, int> um;
	um.insert({ v[0], 1 });
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) um[v[i]]++;
		else um.insert({ v[i], 1 });
	}
	int max_count = 0;
	for (int num : s) max_count = max(um[num], max_count);
	bool issecond = false;
	int mode = v[0];
	for (int num : s) {
		if (um[num] == max_count) {
			if (!issecond) {
				issecond = true;
				mode = num;
			}
			else {
				mode = num; break;
			}
		}
	}
	cout << mode << "\n" << v[N - 1] - v[0];
	return 0;
}