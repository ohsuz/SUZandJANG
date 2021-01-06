def solution(s):
    cnt, total = 0, 0
    
    while not s == '1':
        total += s.count('0')
        cnt += 1
        s = bin(len(s.replace('0', '')))[2:]
        
    return [cnt, total]

'''
정확성  테스트
테스트 1 〉	통과 (0.01ms, 10.3MB)
테스트 2 〉	통과 (1.78ms, 10.3MB)
테스트 3 〉	통과 (0.01ms, 10.2MB)
테스트 4 〉	통과 (0.01ms, 10.1MB)
테스트 5 〉	통과 (0.01ms, 10.2MB)
테스트 6 〉	통과 (0.01ms, 10.2MB)
테스트 7 〉	통과 (0.04ms, 10.2MB)
테스트 8 〉	통과 (0.02ms, 10.2MB)
테스트 9 〉	통과 (0.49ms, 10.3MB)
테스트 10 〉	통과 (2.01ms, 10.3MB)
테스트 11 〉	통과 (1.52ms, 10.3MB)
'''