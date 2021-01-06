#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score;
    vector<int> aanswer = {1,2,3,4,5};
    vector<int> banswer = {2,1,2,3,2,4,2,5};
    vector<int> canswer = {3,3,1,1,2,2,4,4,5,5};
    int ascore=0,bscore=0,cscore=0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i]==aanswer[i%5])
            ascore++;
        if(answers[i]==banswer[i%8])
            bscore++;
        if(answers[i]==canswer[i%10])
            cscore++;
    }
    
    score.push_back(ascore);
    score.push_back(bscore);
    score.push_back(cscore);
    
    sort(score.begin(),score.end(),greater<int>());
    int max = score[0];
    
    if(max==ascore)
        answer.push_back(1);
    if(max==bscore)
        answer.push_back(2);
    if(max==cscore)
        answer.push_back(3);
    
    return answer;
}