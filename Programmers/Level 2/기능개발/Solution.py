def solution(progresses, speeds):
    answer = []

    progresses = progresses[::-1]
    speeds = speeds[::-1]

    while True:
        cnt = 0
        top = progresses[-1]

        while top >= 100 and progresses:
            progresses.pop()
            cnt += 1
            if progresses:
                top = progresses[-1]
        if cnt != 0:
            answer.append(cnt)
            if not progresses:
                break

        for i in range(len(progresses)):
            if progresses[i] < 100:
                progresses[i] += speeds[i]

    return answer