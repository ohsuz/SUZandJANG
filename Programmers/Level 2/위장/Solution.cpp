#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> cloth;
    unordered_map<string,int>::iterator iter;
    
    for(int i=0;i<clothes.size();i++){
        if(cloth.find(clothes[i][1])==cloth.end())
            cloth.insert(make_pair(clothes[i][1],1));
        else
            cloth[clothes[i][1]]++;
    }
    
    for(iter=cloth.begin();iter!=cloth.end();iter++)
        answer *= (iter->second+1);

    answer -= 1;
    return answer;
}