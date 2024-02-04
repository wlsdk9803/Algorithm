#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> know_people;
	vector<vector<int>> party;
	int know_num; cin >> know_num;
	for (int i = 0; i < know_num; i++) {
		int p; cin >> p;
		know_people.push_back(p);
	}
	bool rotation = false;
	for (int i = 0; i < M; i++) {
		vector<int> temp;
		bool is_in_know_people = false;
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int p; cin >> p;
			temp.push_back(p);
			if (!is_in_know_people && find(know_people.begin(), know_people.end(), p) != know_people.end()) is_in_know_people = true;
			
		}
		if (is_in_know_people) {
			for (int j = 0; j < temp.size(); j++) {
				if (find(know_people.begin(), know_people.end(), temp[j]) == know_people.end()) {
					know_people.push_back(temp[j]);
					rotation = true;
				}
			}
		}
		else party.push_back(temp);
	}

	while (rotation) {
		rotation = false;
		for (int i = 0; i < party.size(); i++) {
			bool is_in_know_people = false;
			for (int j = 0; j < party[i].size(); j++) {
				if (find(know_people.begin(), know_people.end(), party[i][j]) != know_people.end()) is_in_know_people = true;
			}
			if (is_in_know_people) {
				for (int j = 0; j < party[i].size(); j++) {
					if (find(know_people.begin(), know_people.end(), party[i][j]) == know_people.end()) {
						know_people.push_back(party[i][j]);
						rotation = true;
					}
				}
				party.erase(party.begin() + i); i--;
			}
		}
	}
	cout << party.size();
	return 0;
}