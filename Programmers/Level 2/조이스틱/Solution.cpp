//문제 오류 있음
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i = 0;
    
    while(true){
        bool check = false;
        
        if(name[i]!='A'){
            if(name[i] <= 'N')
                answer += (name[i] - 'A');
            else
                answer += (91 - name[i]);
            name[i] = 'A';
        }
        
        for(int j=1;j<=name.size();j++){
            int index1 = i-j;
            int index2 = i+j;
            
            if(index1<0)
                index1 = name.size()-1;
            if(index2>=name.size())
                index2 = 0;
            
            if(name[index2]!='A'){
                answer += j;
                i = index2;
                check = true;
                break;
            }
            
            if(name[index1]!='A'){
                answer += j;
                i = index1;
                check = true;
                break;
            }
            
        }
        
        if(!check)
            break;
    }
    
    return answer;
}