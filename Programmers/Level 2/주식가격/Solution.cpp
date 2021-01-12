#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<pair<int,int>> price;
    
    for(int i=0;i<prices.size();i++) {
        if(!price.empty()){
            while(price.top().first>prices[i]){
                answer[price.top().second] = i - price.top().second;
                price.pop();
                
                if(price.empty())
                    break;
            }
        }
        price.push(make_pair(prices[i],i));
    }
    
    int size = price.size();
    for(int i=0;i<size;i++){
        answer[price.top().second] = prices.size() - (price.top().second+1);
        price.pop();
    }
                                                 
    return answer;
}