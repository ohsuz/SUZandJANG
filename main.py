'''
수지의 Replit 연습장
'''
from collections import deque

X = int(input())
d = [0] * (X+1)

for i in range(2, X+1):
  d[i] = d[i-1] + 1
  if i%2 == 0:
    d[i] = min(d[i], d[i//2]+1)
  if i%3 == 0:
    d[i] = min(d[i], d[i//3]+1)

print(d[X])

'''
테스트케이스
100000 // 정답: 18, 오답: 19
643 // 정답: 11, 오답: 12
842 // 정답: 11, 오답: 12
'''