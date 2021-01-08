#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool primeN(int num) {
    vector<int> Num(num+1);
    
    for(int i=2;i<=num;i++){
        if(Num[num]==1)
            return false;
        if(Num[i]==1)
            continue;
        else if(Num[i]==0){
            for(int j=2;i*j<=num;j++)
                Num[i*j]=1;
        }
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i=0;i<nums.size();i++)
        for(int j=i+1;j<nums.size();j++)
            for(int k=j+1;k<nums.size();k++){
                int sum = nums[i]+nums[j]+nums[k];
                if(primeN(sum)){
                    answer++;
                }
            }
    
    return answer;
}