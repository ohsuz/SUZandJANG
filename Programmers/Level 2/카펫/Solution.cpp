#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x,y;
    
    for(int i=1;i*i<=yellow;i++){
        if(yellow%i==0){
            y=i,x=yellow/i;
            if(2*(x+y+2)==brown){
                answer.push_back(x+2);
                answer.push_back(y+2);
            }
        }
    }
    
    return answer;
}