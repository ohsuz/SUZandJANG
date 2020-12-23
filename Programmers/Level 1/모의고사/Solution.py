def solution(answers):
    score = {1:0, 2:0, 3:0}
    one = [1,2,3,4,5] #5
    two = [2,1,2,3,2,4,2,5] #8
    three = [3,3,1,1,2,2,4,4,5,5] #10
    o, tw, th = 0, 0, 0
    
    for i in range(len(answers)):
        print(o)
        if answers[i] == one[o]: score[1] += 1
        if answers[i] == two[tw]: score[2] += 1
        if answers[i] == three[th]: score[3] += 1
        
        if i != 0:
            if (i+1) % 5 == 0:  o = -1
            if (i+1) % 8 == 0: tw = -1
            if (i+1) % 10 == 0: th = -1
        
        o += 1
        tw += 1
        th += 1
        
    return [s for s in score if score[s] == max(score.values())]