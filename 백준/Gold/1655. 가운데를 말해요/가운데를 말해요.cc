#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<int> maxheap, minheap;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (maxheap.size() == minheap.size()) maxheap.push(num);
		else minheap.push(-1 * num);
		while (!maxheap.empty() && !minheap.empty() && maxheap.top() > -1 * minheap.top()) {
			int max_top = maxheap.top();
			int min_top = -1 * minheap.top();
			maxheap.pop(); minheap.pop();
			maxheap.push(min_top);
			minheap.push(-1 * max_top);
		}
		cout << maxheap.top() << "\n";
	}
	return 0;
}