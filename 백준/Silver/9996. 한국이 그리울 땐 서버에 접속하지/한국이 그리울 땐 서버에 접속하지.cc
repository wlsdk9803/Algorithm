#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	int n; cin >> n;
	string std; cin >> std;
	vector<string> splited = split(std, '*');
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		if ((str.length() >= splited[0].size() + splited[1].size()) && str.substr(0, splited[0].length()) == splited[0] && str.substr(str.length() - splited[1].length()) == splited[1]) {
			cout << "DA\n";
		}
		else cout << "NE\n";
	}
	return 0;
}