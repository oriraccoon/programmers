#include <string>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& computers, int n, int start, vector<bool>& visited){
    visited[start] = true;
    for(int next = 0; next < n; next++){
        if(!visited[next] && computers[start][next] == 1){
            dfs(computers, n, next, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            answer++;
            dfs(computers, n, i, visited);
        }
    }
    
    return answer;
}