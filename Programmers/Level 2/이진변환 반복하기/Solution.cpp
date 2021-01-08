#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int trans = 0;
    int remove = 0;
    
    while(1){

        trans++;
        
        for(int i=0;i<s.size();i++)
            if(s[i]=='0'){
                s.erase(s.begin()+i);
                i--;
                remove++;
            }
        
        int num = s.size();
        s = "";
        
        while(num>0){
            s += num%2 + '0';
            num /= 2;
        }
        
        reverse(s.begin(),s.end());
        
        if(s=="1")
            break;
    }
    
    answer.push_back(trans);
    answer.push_back(remove);
        
    return answer;
}