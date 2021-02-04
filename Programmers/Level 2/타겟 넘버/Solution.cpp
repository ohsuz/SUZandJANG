#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph;
int t;

int bfs(int x){
    int result = 0;
    queue<pair<int,int>> q;
    q.push({0,x});
    q.push({0,x*(-1)});
    
    while(!q.empty()){
        int index = q.front().first;
        int sum = q.front().second;
        q.pop();
        
        if(index == graph.size()-1 && sum == t)
            result++;
        
        int nindex = index + 1;
        if(nindex >= graph.size())
            continue;
        
        int nx = graph[nindex];
        int nsum = sum + nx;
        q.push({nindex,nsum});
        
        nx *= (-1);
        nsum = sum + nx;
        q.push({nindex,nsum});
        
    }
    
    return result;
}

int solution(vector<int> numbers, int target) {
    graph = numbers;
    t = target;
    
    int answer = 0;
    answer = bfs(graph[0]);

    return answer;
}