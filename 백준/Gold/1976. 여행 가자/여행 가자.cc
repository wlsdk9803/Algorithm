#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	parent.resize(n);
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int flag; cin >> flag;
			if (flag) merge(i, j);
		}
	}
	char res = 'y';
	int prev = 0;
	for (int i = 0; i < m; i++) {
		int cur; cin >> cur;
		cur--;
		if (i == 0) prev = find(cur);
		else {
			if (prev != find(cur)) {
				res = 'n'; break;
			}
		}
	}
	if (res == 'y') cout << "YES";
	else cout << "NO";
	return 0;
}