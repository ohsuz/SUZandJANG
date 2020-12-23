def solution(dartResult):
    dart = {'S':1, 'D':2, 'T':3}
    scores = []
    n = 0
    
    for i, d in enumerate(dartResult):
        if d in dart:
            scores.append(int(dartResult[n:i])**dart[d])
        if d == "*":
            scores[-2:] = [x*2 for x in scores[-2:]]
        if d == "#":
            scores[-1] = (-1)*scores[-1]
        if not (d.isnumeric()):
            n = i+1
    
    return sum(scores)