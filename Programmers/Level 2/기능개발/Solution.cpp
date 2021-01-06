#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    bool run = true;
    
    while(run){
        int count = 0;
        
        for(int i=0;i<progresses.size();i++){
            if(progresses[i]<100)
                progresses[i] += speeds[i];
        }
        
        for(int i=index;i<progresses.size();i++){
            
            if(progresses[i]>=100)
                count++;
            else{
                index = i;
                break;
            }
            
            if(i==progresses.size()-1&&progresses.back()>=100)
                run = false;
        }
        
        if(count>0)
            answer.push_back(count);
    }
    
    return answer;
}