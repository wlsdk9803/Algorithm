#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		pq.push(num);
	}
	int first = pq.top(); pq.pop();
	int sec = pq.top(); pq.pop();
	int third = pq.top(); pq.pop();
	bool isTriangle = first < sec + third ? true : false;
	int sum = first + sec + third;
	while (!pq.empty()) {
		if (isTriangle) break;
		first = sec; sec = third; 
		third = pq.top(); pq.pop();
		if (first < sec + third) isTriangle = true;
		sum = first + sec + third;
	}
	if (isTriangle) cout << sum;
	else cout << -1;
 	return 0;
}