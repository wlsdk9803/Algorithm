#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> result;
	istringstream iss(str);
	string buffer;
	while (getline(iss, buffer, delimiter)) result.push_back(buffer);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	vector<string> str_list = split(str, ':');
	int hidden = 8 - str_list.size();
	bool isbeforezero = false;
	vector<string> res;
	for (int i = 0; i < str_list.size(); i++) {
		if (i > 0 && str_list[i] == "") {
			if (hidden < 0) continue;
			isbeforezero = true;
		}
		while (str_list[i].length() < 4) str_list[i] = "0" + str_list[i];
		res.push_back(str_list[i]);
		if (isbeforezero) {
			for (int j = 0; j < hidden; j++) res.push_back("0000");
			isbeforezero = false;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i < res.size() - 1) cout << ":";
	}
	return 0;
}