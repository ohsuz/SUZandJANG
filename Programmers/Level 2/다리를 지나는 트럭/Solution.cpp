#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> q; 
    int answer = 1, sum = 0, index = 0;
    
    while(true) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            if(q.front().second > 1)
                q.push({q.front().first,q.front().second - 1});
            else
                sum -= q.front().first;
            
            q.pop();
        }
        
        if(index < truck_weights.size() && weight >= truck_weights[index] + sum) {
            sum += truck_weights[index];
            q.push({truck_weights[index], bridge_length});
            index++;
        }
        
        if(index >= truck_weights.size() && q.empty())
            break;
        
        answer++;
    }
    
    
    return answer;
}