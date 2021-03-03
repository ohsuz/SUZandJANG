using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    
    int c;
    int a = w, b = h;
    while(b!=0){
        c = a % b;
        a = b;
        b = c;
    }
    
    answer = (long long)w * h - (w/a+h/a-1) * a;
    
    return answer;
}