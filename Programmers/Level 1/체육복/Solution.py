def solution(n, lost, reserve):
    answer = n - len(lost)
    
    for r in reserve:
        if r in lost:
            lost.remove(r)
            reserve[reserve.index(r)] = -1
            answer += 1
    
    for l in lost:
        if (l-1) in reserve:
            reserve.remove(l-1)
            answer += 1
        elif (l+1) in reserve:
            reserve.remove(l+1)
            answer += 1

    return answer