#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> results(1);
    
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1]!=0){
                if(board[j][moves[i]-1]==results.back()){
                    answer+=2;
                    results.pop_back();
                }
                else
                    results.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1]=0;
                break;
            }
        }
    }
    
    return answer;
}