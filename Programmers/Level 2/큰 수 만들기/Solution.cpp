#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    
    
    for(int i=0;i<number.size()-k;i++){
        for(int j=index;j<k+i;j++){
            if(number[index]<number[j+1])
                index = j+1;
        }
        answer.push_back(number[index]);
        index++;
    }
    
    return answer;
}