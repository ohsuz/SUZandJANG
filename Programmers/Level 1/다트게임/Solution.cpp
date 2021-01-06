#include <string>
#include <vector>
#include <cmath>

using namespace std;

int calculate(int score, char d){
    if(d=='S')
        score = pow(score,1);
    else if(d=='D')
        score = pow(score,2);
    else if(d=='T')
        score = pow(score,3);
  
    return score;
}

int solution(string dartResult) {
    vector<int> score;
    int answer = 0;
    int tmp = -1;
    
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i]=='S'||dartResult[i]=='D'||dartResult[i]=='T'){
            tmp = calculate(tmp,dartResult[i]);
            score.push_back(tmp);
            tmp = -1;
        }
        else if(dartResult[i]=='*'||dartResult[i]=='#'){
            if(dartResult[i]=='*'){
                score[score.size()-1] *= 2;
                if(score.size()-1!=0)
                    score[score.size()-2] *=2;
            }
            else if(dartResult[i]=='#')
                score[score.size()-1] *= -1;
        }
        else{
            if(tmp == -1)
                tmp = dartResult[i]-'0';
            else
                tmp = 10;
        }
    }
    
    for(int i=0;i<score.size();i++)
        answer += score[i];
    
    return answer;
}