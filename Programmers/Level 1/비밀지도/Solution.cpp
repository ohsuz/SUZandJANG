#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n,"");
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int first = arr1[i]%2;
            int second = arr2[i]%2;
            
            if(first||second)
                answer[i]+='#';
            else
                answer[i]+=' ';
            
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        reverse(answer[i].begin(),answer[i].end());
    }
    
        
    return answer;
}