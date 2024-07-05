#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<>());
    
    int end_idx = people.size() - 1;
    for(int i=0; i<people.size(); i++){
        answer++;
        if(people[i] + people[end_idx] <= limit) end_idx--;
        if(end_idx <= i) break;
    }
    return answer;
}