#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> pos;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		pos.push_back({ x,y });
	}
	sort(pos.begin(), pos.end());
	vector<int> heights;
	for (int i = 0; i < n; i++) heights.push_back(pos[i].second);
	heights.push_back(0);

	stack<int> s;
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if(s.empty()) s.push(heights[i]);
		else {
			bool flag = false;
			if (s.top() < heights[i]) s.push(heights[i]);
			else if (s.top() == heights[i]) continue;
			else {
				while (!s.empty()) {
					if (s.top() == heights[i]) {
						flag = false; break;
					}
					else if (s.top() < heights[i]) {
						s.push(heights[i]); 
						flag = false; break;
					}
					s.pop(); count++;
					flag = true;
				}
				if (flag && heights[i] != 0) s.push(heights[i]);
			}
		}
	}
	cout << count;
	return 0;
}