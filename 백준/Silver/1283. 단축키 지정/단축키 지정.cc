#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
#include <algorithm>

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
	int N; cin >> N;
	cin.ignore();
	unordered_set<char> us;
	for (int i = 0; i < N; i++) {
		string str; getline(cin, str);
		int idx = -1;

		vector<string> words = split(str, ' ');
		int order = -1;
		for (int j = 0; j < words.size(); j++) {
			if (find(us.begin(), us.end(), toupper(words[j][0])) == us.end()) {
				us.insert(toupper(words[j][0]));
				order = j; break;
			}
		}
		if (order != -1) {
			idx = 0;
			for (int j = 0; j < order; j++) idx += words[j].length();
			idx += order;
		}
		if (idx == -1) {
			for (int j = 0; j < str.length(); j++) {
				if (str[j] != ' ' && find(us.begin(), us.end(), toupper(str[j])) == us.end()) {
					us.insert(toupper(str[j]));
					idx = j; break;
				}
			}
		}
		if (idx == -1) cout << str << "\n";
		else cout << str.substr(0, idx) << "[" << str[idx] << "]" << str.substr(idx + 1) << "\n";
	}
	return 0;
}