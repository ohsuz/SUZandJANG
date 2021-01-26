'''
이것이 코딩테스트다 풀이법

bottom up방식으로 구현해서 간결하지만 
X까지 FOR문을 다 돌아서 그런지 내 풀이 시간의 6배가 걸린다
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