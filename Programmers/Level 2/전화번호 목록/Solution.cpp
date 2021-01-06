#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    if(a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end(),compare);
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=i+1;j<phone_book.size();j++){
            if(phone_book[j].find(phone_book[i])==0){
                cout << phone_book[i];
                answer = false;
                break;
            }
        }
        if(answer==false)
            break;
    }
    
    return answer;
}