#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> document;

    for(int i=0;i<priorities.size();i++)
        if(priorities[location]<=priorities[i])
            document.push_back(make_pair(i,priorities[i]));

    while(1){
        bool check = true;
        for(int i=1;i<document.size();i++){
            if(document[0].second<document[i].second){
                document.push_back(document[0]);
                document.erase(document.begin());
                check = false;
                break;
            }
        }

        if(check==true){
            answer++;
            if(document[0].first==location)
                break;
            else
                document.erase(document.begin());
        }

    }

    return answer;
}