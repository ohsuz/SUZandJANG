import collections

def solution(s):
    num = '0123456789'
    temp = ''
    numbers = []

    for i in range(len(s)-1):
        if s[i] in num:
            if s[i+1] in num:
                temp += s[i]
            else:
                if len(temp) != 0:
                    temp += s[i]
                    numbers.append(int(temp))
                    temp = ''
                else:
                    numbers.append(int(s[i]))

    arr = sorted(list(collections.Counter(numbers).items()), 
                 key = lambda x: x[1], reverse = True)

    return [a[0] for a in arr]

'''
정확성  테스트
테스트 1 〉	통과 (0.07ms, 10.4MB)
테스트 2 〉	통과 (0.06ms, 10.3MB)
테스트 3 〉	통과 (0.05ms, 10.4MB)
테스트 4 〉	통과 (0.17ms, 10.3MB)
테스트 5 〉	통과 (0.76ms, 10.3MB)
테스트 6 〉	통과 (1.55ms, 10.4MB)
테스트 7 〉	통과 (18.36ms, 11.1MB)
테스트 8 〉	통과 (54.63ms, 12.9MB)
테스트 9 〉	통과 (29.80ms, 11.4MB)
테스트 10 〉	통과 (58.74ms, 12.9MB)
테스트 11 〉	통과 (79.27ms, 14.2MB)
테스트 12 〉	통과 (157.90ms, 16.4MB)
테스트 13 〉	통과 (148.55ms, 16.4MB)
테스트 14 〉	통과 (150.97ms, 16.5MB)
테스트 15 〉	통과 (0.05ms, 10.3MB)
효율성.. 나가리.....
'''