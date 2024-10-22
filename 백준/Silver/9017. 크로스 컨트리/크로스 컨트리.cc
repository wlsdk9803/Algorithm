#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++) {
		int N; cin >> N;
		vector<int> input(N);
		unordered_map<int, int> um;
		for (int i = 0; i < N; i++) {
			cin >> input[i];
			if (um.find(input[i]) == um.end()) um.insert({ input[i], 1 });
			else um[input[i]]++;
		}
		int score = 1;
		vector<vector<int>> teams(201);
		unordered_set<int> team_nums;
		for (int n : input) {
			if (um[n] < 6) continue;
			teams[n].push_back(score);
			team_nums.insert(n);
			score++;
		}
		unordered_map<int, pair<int, int>> team_score; // 팀 점수, 5등 점수
		for (int n : team_nums) {
			sort(teams[n].begin(), teams[n].end());
			int sum = 0;
			for (int i = 0; i < 4; i++) sum += teams[n][i];
			team_score.insert({ n, {sum, teams[n][4]} });
		}
		pair<int, pair<int, int>> res = make_pair(0, make_pair(6001, 1001)); // 팀 번호, 팀 점수, 5등 점수
		for (int n : team_nums) {
			if ((team_score[n].first < res.second.first) || (team_score[n].first == res.second.first && team_score[n].second < res.second.second)) {
				res = { n ,{team_score[n].first, team_score[n].second} };
			}
		}
		cout << res.first << "\n";
	}
	return 0;
}