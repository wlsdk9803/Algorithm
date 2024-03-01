#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) parent.push_back(i);
	for (int i = 0; i < m; i++) {
		int sign, a, b; cin >> sign >> a >> b;
		if (!sign) merge(a, b);
		if (sign) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}