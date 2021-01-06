#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end(),greater<>());
    
    for(int i=0,j=people.size()-1;i<=j;i++,j--){
        answer++;
        
        if(people[i]+people[j]<=limit)
            continue;
        else
            j++;
    }
    
    return answer;
}