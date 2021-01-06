#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool compare(pair<int,float>& a,pair<int,float> b) {
    if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
    
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,float> stage;
    int tmp = stages.size();
    
    for(int i=1;i<N+1;i++)
        stage.insert(make_pair(i,0));

    for(int i=0;i<stages.size();i++){
        if(stages[i]!=N+1){
            stage[stages[i]]++;
        }
    }
    
    for(int i=1;i<N+1;i++){
        cout << stage.size();
        int tmp2 = stage[i];
        stage[i] = stage[i] / tmp;
        tmp -= tmp2;
        if(tmp==0)
            break;
    }
    
    vector<pair<int,float>> vec(stage.begin(),stage.end());
    
    sort(vec.begin(), vec.end(), compare);
    
    for(int i=0;i<vec.size();i++){
        answer.push_back(vec[i].first);
    }
    
    return answer;
}