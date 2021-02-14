#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int answer1, answer2;

bool check(int x, int y, int size){
    int temp = graph[x][y];
    for(int i=x;i<x+size;i++)
        for(int j=y;j<y+size;j++)
            if(temp != graph[i][j])
                return false;
    return true;
}

void bfs(int x, int y, int size){
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},size});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int size = q.front().second;
        q.pop();
        
        if(check(x,y,size)){
            if(graph[x][y]==0)
                answer1++;
            else if(graph[x][y]==1)
                answer2++;
        } else {
            q.push({{x,y},size/2});
            q.push({{x+size/2,y},size/2});
            q.push({{x,y+size/2},size/2});
            q.push({{x+size/2,y+size/2},size/2});
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    graph = arr;
    answer1 = 0, answer2 = 0;
    
    bfs(0,0,graph.size());
    
    answer.push_back(answer1);
    answer.push_back(answer2);
    return answer;
}