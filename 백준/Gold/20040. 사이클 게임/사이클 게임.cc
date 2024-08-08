#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	int min = a < b ? a : b;
	int max = a < b ? b : a;
	parent[find(max)] = parent[min];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) parent.push_back(i);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i + 1;
			return 0;
		}
		merge(a, b);
	}
	cout << 0;
    return 0;
}