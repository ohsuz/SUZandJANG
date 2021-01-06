#include <string>
#include <vector>

using namespace std;

int distance(int cur, int target){
    int d = abs(target-cur);
    
    if(d==1||d==3)
        d = 1;
    else if(d==2||d==4||d==6)
        d = 2;
    else if(d==5||d==7||d==9)
        d = 3;
    else if(d==8||d==10)
        d = 4;
    
    return d;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 10, left = 12;
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==0)
            numbers[i]=11;
        
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            left = numbers[i];
            answer += 'L';
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            right = numbers[i];
            answer += 'R';
        }
        else{
            int rightd = distance(right,numbers[i]);
            int leftd = distance(left,numbers[i]);
            
            if(rightd>leftd){
                left = numbers[i];
                answer += 'L';
            }
            else if(rightd<leftd){
                right = numbers[i];
                answer += 'R';
            }
            else{
                if(hand == "left"){
                    left = numbers[i];
                    answer += 'L';
                }
                else if(hand == "right"){
                    right = numbers[i];
                    answer += 'R';
                }
            }
        }
                
    }
    return answer;
}