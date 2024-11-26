#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cin.ignore();
	vector<vector<int>> edge(26);
	for (int i = 0; i < n; i++) {
		string str; getline(cin, str);
		int fir = str[0] - 'a', sec = str[5] - 'a';
		edge[fir].push_back(sec);
	}
	int m; cin >> m;
	cin.ignore();
	for (int i = 0; i < m; i++) {
		string str; getline(cin, str);
		int fir = str[0] - 'a', sec = str[5] - 'a';
		queue<int> q;
		vector<bool> visited(26);
		q.push(fir); visited[fir] = true;
		bool istrue = false;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == sec) {
				istrue = true; break;
			}
			for (int next : edge[cur]) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}
		if (istrue) cout << "T\n";
		else cout << "F\n";
	}
	return 0;
}