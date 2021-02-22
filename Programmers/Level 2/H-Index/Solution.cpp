#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    int hindex = citations[0];
    
    for(int i=hindex;i>0;i--){
        
        if(i > citations.size())
            continue;
        
        if(citations[i-1] >= i){
            answer = i;
            break;
        }
    }
    
    return answer;
}