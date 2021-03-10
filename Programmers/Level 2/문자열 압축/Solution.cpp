#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    vector<string> arr;
    int answer = s.length();
    
    for(int i=1;i<=s.length()/2;i++){
        int count = 1;
        int result = s.length();
        string temp = s.substr(0,i);

        for(int j=i;j<s.length();j = j+i){
            string str1 = s.substr(j,i);
            if(str1 == temp) {
                count++;
                result -= i;
            }
            else {
                temp = str1;
                if(count > 1) {
                    result += to_string(count).length();
                    count = 1;
                }
            }
            
        }
        if(count > 1)
            result += to_string(count).length();

        answer = min(answer, result);
    }
    
    return answer;
}