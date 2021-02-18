//두시간동안 풀었는데 정답이랑 완전 다른방향이었다...ㅎㅎ...
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    
    for(int i=0;i<numbers.size();i++)
        num.push_back(to_string(numbers[i]));
    
    sort(num.begin(),num.end(),compare);
    
    for(int i=0;i<num.size();i++){
        if(answer == "" && num[i] == "0")
            continue;
        answer += num[i];
    }
    
    if(answer == "")
        answer = "0";
    
    return answer;
}