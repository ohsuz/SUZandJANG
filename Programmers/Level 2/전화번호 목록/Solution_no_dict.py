def solution(phone_book):
    phones = sorted(phone_book, key = len)
    
    for i in range(len(phones)):
        for j in range(i+1, len(phones)):
            if phones[i] == phones[j][:len(phones[i])]:
                return False

    return True

'''
생각해보니 딕셔너리가 굳이 필요 없어서 이전 solution에서 수정함

정확성  테스트
테스트 1 〉	통과 (0.01ms, 10.2MB)
테스트 2 〉	통과 (0.01ms, 10.2MB)
테스트 3 〉	통과 (0.01ms, 10MB)
테스트 4 〉	통과 (0.01ms, 10.2MB)
테스트 5 〉	통과 (0.01ms, 10.2MB)
테스트 6 〉	통과 (0.01ms, 10.2MB)
테스트 7 〉	통과 (0.01ms, 10.2MB)
테스트 8 〉	통과 (0.01ms, 10.1MB)
테스트 9 〉	통과 (0.01ms, 10.2MB)
테스트 10 〉	통과 (0.01ms, 10.1MB)
테스트 11 〉	통과 (0.01ms, 10.2MB)
효율성  테스트
테스트 1 〉	통과 (1.31ms, 11MB)
테스트 2 〉	통과 (1.30ms, 11MB)
'''