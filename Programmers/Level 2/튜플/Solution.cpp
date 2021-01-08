#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int isin(string s, vector<pair<string,int>> vec){
    for(int i=0;i<vec.size();i++)
        if(vec[i].first==s)
            return i;
    return -1;
}

bool compare(pair<string,int> a, pair<string,int> b) {
    if(a.second == b.second) return a.first<b.first;
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<string,int>> tuple;
    string tmp = "";
    
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57)
            tmp += s[i];
        else if((s[i]==','||s[i]=='}')&&tmp!=""){
            if(isin(tmp,tuple)==-1)
                tuple.push_back(make_pair(tmp,1));
            else     
                tuple[isin(tmp,tuple)].second++;
            tmp = "";
        }
    }
    
    sort(tuple.begin(),tuple.end(),compare);
    
    for(int i=0;i<tuple.size();i++){
        int n = atoi(tuple[i].first.c_str());
        answer.push_back(n);
    }
    
    return answer;
}