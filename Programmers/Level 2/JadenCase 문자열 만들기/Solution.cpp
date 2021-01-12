#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<string> str;
    
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '&&temp==""&&s[i]>=97&&s[i]<=122)
            temp += s[i]-32;
        else if(temp!=""&&s[i]>=65&&s[i]<=90)
            temp += s[i] + 32;
        else if(s[i]==' '){
            temp += s[i];
            answer += temp;
            temp = "";
        }
        else
            temp += s[i];
    }
    
    answer += temp;
    
    return answer;
}