from itertools import combinations
from functools import reduce

def solution(clothes):
    answer = 0
    closet = {}
    is_all_one = True
    
    for cloth in clothes:
        if cloth[1] not in closet:
            closet[cloth[1]] = 1
        else:
            closet[cloth[1]] += 1
            is_all_one = False
    
    arr = list(closet.values())
    
    # Test Case 1: 모든 종류의 옷이 한가지씩만 있는 경우
    # 경우의 수 = 2**n - 1
    if is_all_one:
        return (2**len(arr) - 1)    
    
    for i in range(1, len(arr)+1):
        for c in combinations(arr, i):
            answer += reduce(lambda x, y: x*y, c)
            
    return answer

'''
정확성  테스트
테스트 1 〉	통과 (0.01ms, 10.2MB)
테스트 2 〉	통과 (0.01ms, 10.1MB)
테스트 3 〉	통과 (0.09ms, 10.1MB)
테스트 4 〉	통과 (192.71ms, 10.2MB)
테스트 5 〉	통과 (0.09ms, 10.2MB)
테스트 6 〉	통과 (0.02ms, 10.2MB)
테스트 7 〉	통과 (192.56ms, 10.2MB)
테스트 8 〉	통과 (1.54ms, 10.3MB)
테스트 9 〉	통과 (0.01ms, 10.2MB)
테스트 10 〉	통과 (0.01ms, 10.2MB)
테스트 11 〉	통과 (0.03ms, 10.2MB)
테스트 12 〉	통과 (5.60ms, 10.3MB)
테스트 13 〉	통과 (22.02ms, 10.1MB)
테스트 14 〉	통과 (0.03ms, 10.2MB)
테스트 15 〉	통과 (0.01ms, 10.2MB)
테스트 16 〉	통과 (0.01ms, 10.3MB)
테스트 17 〉	통과 (0.02ms, 10.1MB)
테스트 18 〉	통과 (0.19ms, 10.2MB)
테스트 19 〉	통과 (1.56ms, 10.2MB)
테스트 20 〉	통과 (0.01ms, 10.2MB)
테스트 21 〉	통과 (0.01ms, 10.2MB)
테스트 22 〉	통과 (0.01ms, 10.2MB)
테스트 23 〉	통과 (0.02ms, 10.1MB)
테스트 24 〉	통과 (0.02ms, 10.2MB)
테스트 25 〉	통과 (0.93ms, 10.2MB)
테스트 26 〉	통과 (400.82ms, 10.1MB)
테스트 27 〉	통과 (0.01ms, 10.2MB)
테스트 28 〉	통과 (0.86ms, 10.3MB)
'''