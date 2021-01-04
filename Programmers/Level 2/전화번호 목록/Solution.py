def solution(phone_book):
    answer = True
    dict_books = {}

    for phone in sorted(phone_book):
        temp = dict_books.get(len(phone), [])
        temp.append(phone)
        dict_books[len(phone)] = temp

    books = list(dict_books.values())

    for i in range(len(books)):
        temp1 = books[i]
        for j in range(i+1, len(books)):
            temp2 = books[j]
            for t1 in temp1:
                for t2 in temp2: # ㅋㅋㅋㅋㅋㅋㅋㅋ4중 포문 미쳤네ㅠㅠ
                    if t1 == t2[:len(t1)]:
                        return False

    return answer

'''
정확성  테스트
테스트 1 〉	통과 (0.02ms, 10.1MB)
테스트 2 〉	통과 (0.01ms, 10.1MB)
테스트 3 〉	통과 (0.01ms, 10.2MB)
테스트 4 〉	통과 (0.01ms, 10.2MB)
테스트 5 〉	통과 (0.02ms, 10.2MB)
테스트 6 〉	통과 (0.01ms, 10.2MB)
테스트 7 〉	통과 (0.01ms, 10.1MB)
테스트 8 〉	통과 (0.01ms, 10.2MB)
테스트 9 〉	통과 (0.01ms, 10.2MB)
테스트 10 〉	통과 (0.01ms, 10.2MB)
테스트 11 〉	통과 (0.02ms, 10.2MB)
효율성  테스트
테스트 1 〉	통과 (5.37ms, 10.8MB)
테스트 2 〉	통과 (5.25ms, 10.9MB)

'''