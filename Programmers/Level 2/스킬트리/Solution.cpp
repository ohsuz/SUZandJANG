#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(int i=0;i<skill_trees.size();i++){
        int count = 0;
        bool check = true;
        for(int j=0;j<skill_trees[i].size();j++){
            if(skill.find(skill_trees[i][j])==string::npos)
                continue;
            else if(skill.find(skill_trees[i][j])==count)
                count++;
            else{
                check = false;
                break;
            }
        }

        if(check)
            answer++;

    }

    return answer;
}