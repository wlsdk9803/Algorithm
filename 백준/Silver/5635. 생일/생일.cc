#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	priority_queue<pair<pair<int, int>, pair<int, string>>> max_pq;
	priority_queue<pair<pair<int, int>, pair<int, string>>> min_pq;
	for (int i = 0; i < n; i++) {
		string name;
		int day, month, year;
		cin >> name >> day >> month >> year;
		max_pq.push({ {year, month}, {day, name} });
		min_pq.push({ {-year, -month}, {-day, name} });
	}
	cout << max_pq.top().second.second << "\n" << min_pq.top().second.second;
	return 0;
}