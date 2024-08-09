#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unordered_map<string, double> grade;
	grade.insert({ "A+", 4.5 }); grade.insert({ "A0", 4.0 }); grade.insert({ "B+", 3.5 });
	grade.insert({ "B0", 3.0 }); grade.insert({ "C+", 2.5 }); grade.insert({ "C0", 2.0 });
	grade.insert({ "D+", 1.5 }); grade.insert({ "D0", 1.0 }); grade.insert({ "F", 0.0 });
	
	double sum = 0;
	int sum_weight = 0;
	while (true) {
		string subject;
		double weight;
		string score;
		cin >> subject >> weight >> score;
		if (cin.eof()) break;
		if (score == "P") continue;
		sum += (weight * grade[score]);
		sum_weight += weight;
	}
	cout << sum / sum_weight;
    return 0;
}