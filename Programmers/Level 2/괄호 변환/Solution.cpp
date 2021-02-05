#include <string>
#include <vector>
#include <stack>

using namespace std;

string dfs(string p) {
    string u = "", v = "", answer = "";
    
    if(p.empty())
        return "";
    
    while(true){
        int left = 0, right = 0;
        stack<char> st;
        bool check = false;
        
        if(p.empty())
            return answer;
        
        u = "";
        v = "";
        
        for(int i=0;i<p.size();i++){
            if(check){
                v += p[i];
                continue;
            }
            
            u += p[i];
            
            if(st.empty())
                st.push(p[i]);
            else {
                if(st.top() == '(' && p[i] == ')')
                    st.pop();
                else
                    st.push(p[i]);
            }
            
            if(p[i] == '(')
                left++;
            else
                right++;
            
            if(left == right && left != 0 && right != 0)
                check = true;
        }
        
        if(!st.empty())
            break;
        
        answer += u;
        p = v;
        
        if(p == "")
            return answer;
    }
    
    answer = answer + "(" + dfs(v) + ")";
    
    for(int i=1;i<u.size()-1;i++){
        if(u[i]=='(')
            answer += ")";
        else
            answer += "(";
    }
    
    return answer;
}

string solution(string p) {
    string answer = "";
    
    answer = dfs(p);
    
    return answer;
}