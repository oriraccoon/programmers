#include <string>
#include <vector>

using namespace std;

int maxcount = 0;

int explore(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int count){

    if(count > maxcount)    maxcount = count;
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            explore(k - dungeons[i][1], dungeons, visited, count + 1);
            visited[i] = false;
        }
    }
    return maxcount;
    
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int count = 0;
    int n = dungeons.size();
    vector<bool> visited(n, false);
    answer = explore(k, dungeons, visited, count);
    
    
    return answer;
}