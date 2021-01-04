def solution(people, limit):
    answer = 0
    people.sort(reverse = True)
    
    index = -1
    for i in range(len(people)):
        if people[i] == 0:
            break
        if people[i] + people[index] <= limit:
            people[index] = 0
            index -= 1
        answer += 1
        
    return answer


'''
정확성  테스트
테스트 1 〉	통과 (1.33ms, 10.2MB)
테스트 2 〉	통과 (1.13ms, 10.2MB)
테스트 3 〉	통과 (0.99ms, 10.1MB)
테스트 4 〉	통과 (0.96ms, 10.1MB)
테스트 5 〉	통과 (0.56ms, 10.2MB)
테스트 6 〉	통과 (0.30ms, 10.1MB)
테스트 7 〉	통과 (0.51ms, 10.2MB)
테스트 8 〉	통과 (0.05ms, 10.2MB)
테스트 9 〉	통과 (0.08ms, 10.3MB)
테스트 10 〉	통과 (0.97ms, 10.1MB)
테스트 11 〉	통과 (0.79ms, 10.3MB)
테스트 12 〉	통과 (0.73ms, 10.2MB)
테스트 13 〉	통과 (0.97ms, 10.1MB)
테스트 14 〉	통과 (1.18ms, 10.3MB)
테스트 15 〉	통과 (0.10ms, 10.1MB)
효율성  테스트
테스트 1 〉	통과 (9.52ms, 10.6MB)
테스트 2 〉	통과 (10.33ms, 10.6MB)
테스트 3 〉	통과 (9.14ms, 10.7MB)
테스트 4 〉	통과 (10.26ms, 10.6MB)
테스트 5 〉	통과 (9.33ms, 10.6MB)
'''
