#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i=0;i<completion.size();i++)
        participant.push_back(completion[i]);
    
    sort(participant.begin(),participant.end());
    
    for(int i=0;i<participant.size();i+=2){
        if(i==participant.size()-1){
            answer = participant[i];
            break;
        }
        if(participant[i]==participant[i+1])
            continue;
        else{
            answer = participant[i];
            break;
        }
    }
        
    return answer;
}