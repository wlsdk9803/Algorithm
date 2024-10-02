#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> v;
	for(int i=1; i<=N; i++){
		int num; cin>>num;
		v.push_back({num, i});
	}
	sort(v.begin(), v.end(), greater<>());
	for(int i=0; i<3; i++) {
		cout << v[i].second;
		if(i==2) cout << "\n";
		else cout << " ";
	}
	return 0;
}