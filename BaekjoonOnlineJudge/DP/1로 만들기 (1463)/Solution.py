'''
[틀린 횟수] 2번
1st - 극단값 미처리
: X가 1일때 처리를 안해줬다 X는 더 연산해줄 필요 없이 바로 1이므로 바로 0을 프린트 해줘야 함
2st - 이미 값이 있어도 현재 가지고 온 값이 더 작다면 교체해줘야 한다
: 방문한 적 없을 때만 값을 집어넣도록 했는데 방문을 했어도 현재 값이 더 작으면 교체를 해줘야한다

[사용한 테스트 케이스]
100000 // 정답: 18, 오답: 19
643 // 정답: 11, 오답: 12
842 // 정답: 11, 오답: 12
'''

from collections import deque

X = int(input())
memo = [0] * (X+1)
cur = deque([X])

if X == 1:
  print(0)
else:  
  while cur and memo[1] == 0:
    c = cur.popleft()
    if c % 3 == 0:
      if memo[c//3] == 0:
        memo[c//3] = memo[c] + 1
        cur.append(c//3)
      else:
        if memo[c//3] > memo[c] + 1:
          memo[c//3] = memo[c] + 1
          cur.append(c//3)
    if c % 2 == 0:
      if memo[c//2] == 0:
        memo[c//2] = memo[c] + 1
        cur.append(c//2)
      else:
        if memo[c//2] > memo[c] + 1:
          memo[c//2] = memo[c] + 1
          cur.append(c//2)
    if memo[c-1] == 0:
      memo[c-1] = memo[c] + 1
      cur.append(c-1)
    else:
      if memo[c-1] > memo[c] + 1:
        memo[c-1] = memo[c] + 1
        cur.append(c-1)
    
  print(memo[1])