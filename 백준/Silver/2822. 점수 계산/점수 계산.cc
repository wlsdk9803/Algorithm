#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= 8; i++) {
		int score; cin >> score;
		pq.push({ score, i });
	}
	int sum = 0;
	vector<int> num;
	while (pq.size() > 3) {
		sum += pq.top().first; 
		num.push_back(pq.top().second);
		pq.pop();
	}
	sort(num.begin(), num.end());
	cout << sum << "\n";
	for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
	return 0;
}