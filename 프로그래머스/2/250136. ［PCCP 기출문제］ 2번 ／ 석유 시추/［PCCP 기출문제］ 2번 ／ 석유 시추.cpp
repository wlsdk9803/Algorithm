#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isValid(int row, int col, int n, int m){
    return row >= 0 && row < n && col >= 0 && col < m;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size(), m = land[0].size();
    int sign = 1;
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m)); //sign, 덩어리 크기
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && land[i][j]) {
                int size = 1;
                queue<pair<int, int>> pos;
                queue<pair<int, int>> q;
                pos.push({i, j});
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()){
                    int cur_row = q.front().first;
                    int cur_col = q.front().second; q.pop();
                    for(int idx = 0; idx<4; idx++){
                        int next_row = cur_row + dy[idx];
                        int next_col = cur_col + dx[idx];
                        if(isValid(next_row, next_col, n, m) && !visited[next_row][next_col] && land[next_row][next_col]){
                            pos.push({next_row, next_col});
                            q.push({next_row, next_col});
                            visited[next_row][next_col] = true;
                            size++;
                        }
                    }
                }
                while(!pos.empty()){
                    int row = pos.front().first;
                    int col = pos.front().second; pos.pop();
                    v[row][col] = make_pair(sign, size);
                }
                sign++;
            }
        }
    }
    
    for(int j=0; j<m; j++){
        unordered_map<int, bool> um; //sign 존재 여부 확인 위함
        int sum = 0;
        for(int i=0; i<n; i++){
            int sign = v[i][j].first;
            int size = v[i][j].second;
            if(size >= 1 && um.find(sign) == um.end()){
                sum += size;
                um.insert({sign, true});
            }
        }
        answer = sum > answer ? sum : answer;
    }
    
    
    return answer;
}