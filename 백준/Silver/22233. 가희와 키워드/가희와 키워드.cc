#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	istringstream iss(str);
	string buffer;
	vector<string> result;
	while (getline(iss, buffer, delimiter)) result.push_back(buffer);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	unordered_map<string, int> um; //1이면 유효, 0이면 이미 등장한 것
	for (int i = 0; i < N; i++) {
		string keyword; cin >> keyword;
		um.insert({ keyword, 1 });
	}
	for (int i = 0; i < M; i++) {
		string comd; cin >> comd;
		vector<string> buf = split(comd, ',');
		for (int j = 0; j < buf.size(); j++) {
			if (um.find(buf[j]) != um.end() && um[buf[j]] == 1) {
				um[buf[j]] = 0;
				N--;
			}
		}
		cout << N << "\n";
	}
	return 0;
}