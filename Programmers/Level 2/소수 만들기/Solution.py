from itertools import combinations

def solution(nums):
    arr = [c[0]+c[1]+c[2] for c in list(combinations(nums, 3))]
    return len([a for a in arr if is_prime(a)])

def is_prime(n):
    if n == 1 or n == 2:
        return False
    for i in range(2, int(n**1/2)+1):
        if n % i == 0:
            return False
    return True

'''
정확성  테스트
테스트 1 〉	통과 (3.21ms, 10.3MB)
테스트 2 〉	통과 (4.60ms, 10.4MB)
테스트 3 〉	통과 (1.19ms, 10.3MB)
테스트 4 〉	통과 (1.05ms, 10.2MB)
테스트 5 〉	통과 (6.21ms, 10.3MB)
테스트 6 〉	통과 (14.74ms, 10.6MB)
테스트 7 〉	통과 (0.75ms, 10.2MB)
테스트 8 〉	통과 (40.11ms, 11.4MB)
테스트 9 〉	통과 (3.06ms, 10.3MB)
테스트 10 〉	통과 (29.38ms, 11.3MB)
테스트 11 〉	통과 (0.27ms, 10.2MB)
테스트 12 〉	통과 (0.09ms, 10.1MB)
테스트 13 〉	통과 (0.24ms, 10.2MB)
테스트 14 〉	통과 (0.09ms, 10.2MB)
테스트 15 〉	통과 (0.08ms, 10.2MB)
테스트 16 〉	통과 (76.09ms, 11.6MB)
테스트 17 〉	통과 (17.02ms, 12.2MB)
테스트 18 〉	통과 (1.34ms, 10.2MB)
테스트 19 〉	통과 (0.13ms, 10.3MB)
테스트 20 〉	통과 (115.28ms, 12.2MB)
테스트 21 〉	통과 (90.16ms, 12.1MB)
테스트 22 〉	통과 (3.29ms, 10.5MB)
테스트 23 〉	통과 (0.01ms, 10.2MB)
테스트 24 〉	통과 (77.70ms, 11.6MB)
테스트 25 〉	통과 (73.46ms, 11.7MB)
테스트 26 〉	통과 (0.01ms, 10.2MB)
'''