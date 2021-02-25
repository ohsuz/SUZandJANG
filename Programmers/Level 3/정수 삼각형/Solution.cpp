#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp = triangle;
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0)
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if(j==triangle[i].size()-1)
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
        }
    }
    
    int size = triangle.size()-1;
    for(int i=1;i<triangle[size].size();i++)
        answer = max(answer,dp[size][i]);
    
    return answer;
}