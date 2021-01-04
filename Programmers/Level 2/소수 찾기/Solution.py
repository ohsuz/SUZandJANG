from itertools import permutations

def solution(numbers):
    answer = 0
    numbers = list(numbers)
    result = []
    
    for i in range(1, len(numbers)+1):
        for p in permutations(numbers, i):
            result.append(''.join(p))
            
    result = list(set(result)) # 중복 제거
    
    for r in result:
        if r[0] != '0' and is_prime(int(r)): 
            print(r)
            answer += 1

    return answer

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False
    return True

'''
정확성  테스트
테스트 1 〉	통과 (0.10ms, 10.3MB)
테스트 2 〉	통과 (3.40ms, 10.5MB)
테스트 3 〉	통과 (0.04ms, 10.2MB)
테스트 4 〉	통과 (0.98ms, 10.5MB)
테스트 5 〉	통과 (3.71ms, 11MB)
테스트 6 〉	통과 (0.04ms, 10.5MB)
테스트 7 〉	통과 (0.10ms, 10.4MB)
테스트 8 〉	통과 (4.01ms, 11.1MB)
테스트 9 〉	통과 (0.06ms, 10.5MB)
테스트 10 〉	통과 (6.36ms, 10.6MB)
테스트 11 〉	통과 (1.10ms, 10.4MB)
테스트 12 〉	통과 (0.32ms, 10.4MB)
'''