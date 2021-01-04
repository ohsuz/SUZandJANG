def solution(n):
    answer = 1 # 자기 자신일 때

    for i in range(1,n//2+1):
        sum = i
        for j in range(i+1, n//2+2):
            sum += j
            if sum == n:
                answer += 1
                break
            if sum > n:
                break

    return answer