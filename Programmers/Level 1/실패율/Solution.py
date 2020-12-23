def solution(N, stages):
    dict = {}
    cnt = stages.count(N+1)
    
    for i in range(N, 0, -1):
        cnt += stages.count(i)
        if cnt == 0:
            dict[i] = 0
        else:
            dict[i] = stages.count(i)/cnt

    result = sorted(dict.items(), key = lambda x: (-x[1], x[0]))
    answer = [x[0] for x in result]
    
    return answer