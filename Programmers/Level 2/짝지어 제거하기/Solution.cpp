#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(st.top()!=s[i]){
            st.push(s[i]);
        }
        else if(st.top()==s[i]){
            st.pop();
        }
    }
    
    if(st.empty())
        answer = 1;

    return answer;
}