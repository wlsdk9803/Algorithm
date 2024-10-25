#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, int> score;

int find_winner(int a, int b) {
	if (score[a] > score[b]) return a;
	else if (score[a] < score[b]) return b;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int total_sec = 48 * 60;
	unordered_map<int, int> res;
	res.insert({ 1, 0 }); res.insert({ 2, 0 });
	score.insert({ 1, 0 }); score.insert({ 2, 0 });
	int prev_sec = 0;
	for (int i = 0; i <= N; i++) {
		if (i == N) {
			int winner = find_winner(1, 2);
			if (winner != 0) res[winner] += (total_sec - prev_sec);
			break;
		}
		int team; cin >> team;
		string time; cin >> time;
		int min = stoi(time.substr(0, 2));
		int sec = stoi(time.substr(3));
		int time_sec = min * 60 + sec;
		if (i > 0) {
			int winner = find_winner(1, 2);
			if (winner != 0) res[winner] += (time_sec - prev_sec);
		}
		prev_sec = time_sec;
		score[team]++;
	}
	string team1_min = res[1] / 60 < 10 ? "0" + to_string(res[1] / 60) : to_string(res[1] / 60);
	string team1_sec = res[1] % 60 < 10 ? "0" + to_string(res[1] % 60) : to_string(res[1] % 60);
	string team2_min = res[2] / 60 < 10 ? "0" + to_string(res[2] / 60) : to_string(res[2] / 60);
	string team2_sec = res[2] % 60 < 10 ? "0" + to_string(res[2] % 60) : to_string(res[2] % 60);
	cout << team1_min << ":" << team1_sec << "\n" << team2_min << ":" << team2_sec;
	return 0;
}