#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n>0){
        int num = n % 3;
        
        if(num==0){
            answer.push_back('4');
            n = (n-1)/3;
        }
        else {
            n /= 3;
            if(num==1)
                answer.push_back('1');
            else if(num==2)
                answer.push_back('2');
        }
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}