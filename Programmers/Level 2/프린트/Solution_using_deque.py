from collections import deque

def solution(priorities, location):
    done = []
    docs = deque(list(zip(priorities, list(range(len(priorities))))))
    
    while len(docs) > 1:
        temp = docs.popleft()
        if temp[0] >= max(docs)[0]:
            done.append(temp[1])
        else:
            docs.append(temp)
    done.append(docs.popleft()[1])
    
    return done.index(location) + 1

'''
테스트 1 〉	통과 (0.38ms, 10.2MB)
테스트 2 〉	통과 (1.25ms, 10.1MB)
테스트 3 〉	통과 (0.79ms, 10MB)
테스트 4 〉	통과 (0.22ms, 10.2MB)
테스트 5 〉	통과 (0.01ms, 10.1MB)
테스트 6 〉	통과 (0.20ms, 10.2MB)
테스트 7 〉	통과 (0.36ms, 10.2MB)
테스트 8 〉	통과 (1.27ms, 10.2MB)
테스트 9 〉	통과 (0.03ms, 10.1MB)
테스트 10 〉	통과 (0.22ms, 10.2MB)
테스트 11 〉	통과 (1.09ms, 10.2MB)
테스트 12 〉	통과 (0.29ms, 10.3MB)
테스트 13 〉	통과 (1.00ms, 10.2MB)
테스트 14 〉	통과 (0.01ms, 10.2MB)
테스트 15 〉	통과 (0.12ms, 10.3MB)
테스트 16 〉	통과 (0.09ms, 10.2MB)
테스트 17 〉	통과 (1.61ms, 10.1MB)
테스트 18 〉	통과 (0.03ms, 10.2MB)
테스트 19 〉	통과 (1.35ms, 10.2MB)
테스트 20 〉	통과 (0.70ms, 10.2MB)

=> Better efficiency than the previous solution not using deque
'''