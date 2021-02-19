#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool alphabet(char c) {
    if(65<=c && c<=90)
        return true;
    else if(97<=c && c<=122)
        return true;
    else
        return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    double arr1 = 0, arr2 = 0;
    map<string,int> m;
    
    for(int i=0;i<str1.length()-1;i++) {
        if(alphabet(str1[i])&&alphabet(str1[i+1])){
            string s = ""; 
            s = toupper(str1[i]);
            s += toupper(str1[i+1]);
            
            arr2++;
            if(!m.count(s)) 
                m.insert(make_pair(s,1));
            else if(m.count(s))
                m[s] += 1;
        }
    }
    
    for(int i=0;i<str2.length()-1;i++){
        if(alphabet(str2[i])&&alphabet(str2[i+1])){
            string s = ""; 
            s = toupper(str2[i]);
            s += toupper(str2[i+1]);
            
            if(!m.count(s) || m[s] == 0) {
                arr2++;
            }
            else if (m.count(s)){
                m[s] -= 1;
                arr1++;
            }
        }
    }
    
    if(arr2 == 0)
        return 65536;
    else if (arr1 == 0)
        return 0;
    
    answer = arr1/arr2 * 65536;
    
    return answer;
}