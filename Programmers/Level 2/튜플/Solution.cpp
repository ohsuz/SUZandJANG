#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int isin(int s, vector<pair<int,int>> vec){
    for(int i=0;i<vec.size();i++)
        if(vec[i].first==s)
            return i;
    return -1;
}

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) return a.first<b.first;
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> tuple;
    int tmp = 0;

    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            tmp *= 10;
            tmp += s[i]-'0';
        }
        else if((s[i]==','||s[i]=='}')&&tmp!=0){
            if(isin(tmp,tuple)==-1)
                tuple.push_back(make_pair(tmp,1));
            else     
                tuple[isin(tmp,tuple)].second++;
            tmp = 0;
        }
    }

    sort(tuple.begin(),tuple.end(),compare);

    for(int i=0;i<tuple.size();i++){
        int n = tuple[i].first;
        answer.push_back(n);
    }

    return answer;
}