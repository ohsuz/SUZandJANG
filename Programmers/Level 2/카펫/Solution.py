def solution(brown, yellow):
    answer = []
    total = brown + yellow
    
    if yellow == 1:
        return [3, 3]
    
    for i in range(1, yellow):
        if yellow%i == 0 and total % (yellow//i + 2) == 0:
            answer.append(yellow//i + 2)
            answer.append(total//answer[0])
            break

    return answer

'''
테스트 1 〉	통과 (0.01ms, 10.2MB)
테스트 2 〉	통과 (0.01ms, 10MB)
테스트 3 〉	통과 (0.06ms, 10.2MB)
테스트 4 〉	통과 (0.00ms, 10.2MB)
테스트 5 〉	통과 (0.01ms, 10.1MB)
테스트 6 〉	통과 (0.03ms, 10.2MB)
테스트 7 〉	통과 (0.08ms, 10.2MB)
테스트 8 〉	통과 (0.09ms, 10.1MB)
테스트 9 〉	통과 (0.09ms, 10.2MB)
테스트 10 〉	통과 (0.11ms, 10.1MB)
테스트 11 〉	통과 (0.00ms, 10.2MB)
테스트 12 〉	통과 (0.00ms, 10.2MB)
테스트 13 〉	통과 (0.01ms, 10.1MB)
'''