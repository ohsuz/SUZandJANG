def solution(board, moves):
    answer = 0
    basket = []
    
    ## 인형 쌓기
    for m in moves:
        for b in board:
            if b[m-1] != 0:
                basket.append(b[m-1])
                b[m-1] = 0
                break
    
    ## 인형 터트리기
    i = 0
    while len(basket)>1 and len(basket)-1 != i:
        if basket[i] == basket[i+1]:
            answer += 2
            basket[i:i+2] = []
            i -= 1
        else:
            i += 1

    return answer