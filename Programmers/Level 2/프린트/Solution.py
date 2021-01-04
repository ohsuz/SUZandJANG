def solution(priorities, location):
    done = []
    docs = list(zip(list(range(len(priorities))),
                   priorities))

    while len(docs) > 1:
        temp = docs.pop(0)
        if temp[1] >= max([d[1] for d in docs]):
            done.append(temp[0])
        else:
            docs.append(temp)
    done.append(docs.pop()[0])

    return done.index(location) + 1

'''
테스트 1 〉	통과 (0.47ms, 10.2MB)
테스트 2 〉	통과 (2.28ms, 10.2MB)
테스트 3 〉	통과 (1.66ms, 10.2MB)
테스트 4 〉	통과 (0.37ms, 10.2MB)
테스트 5 〉	통과 (0.01ms, 10.2MB)
테스트 6 〉	통과 (0.32ms, 10.2MB)
테스트 7 〉	통과 (0.58ms, 10.2MB)
테스트 8 〉	통과 (2.11ms, 10.2MB)
테스트 9 〉	통과 (0.05ms, 10.2MB)
테스트 10 〉	통과 (0.34ms, 10.3MB)
테스트 11 〉	통과 (1.37ms, 10.1MB)
테스트 12 〉	통과 (0.45ms, 10.2MB)
테스트 13 〉	통과 (1.25ms, 10.2MB)
테스트 14 〉	통과 (0.01ms, 10.2MB)
테스트 15 〉	통과 (0.18ms, 10.1MB)
테스트 16 〉	통과 (0.11ms, 10.2MB)
테스트 17 〉	통과 (2.11ms, 10.2MB)
테스트 18 〉	통과 (0.04ms, 10.2MB)
테스트 19 〉	통과 (1.78ms, 10.2MB)
테스트 20 〉	통과 (1.02ms, 10.2MB)
'''