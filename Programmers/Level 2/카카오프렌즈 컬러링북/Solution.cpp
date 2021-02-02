#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int M,N;
bool visited[100][100];

int bfs(int x, int y){
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    int area = 1;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    visited[x][y] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0||nx>=M||ny<0||ny>=N)
                continue;
            
            if(!visited[nx][ny]&&graph[x][y]==graph[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx,ny});
                area++;
            }
            
        }
    }
    
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    graph = picture;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++)
            visited[i][j] = false;
    }
    M = m;
    N = n;
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            if(graph[i][j]!=0&&!visited[i][j]){
                number_of_area++;
                
                int area = bfs(i,j);
                if(area>max_size_of_one_area)
                    max_size_of_one_area = area;
            }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}