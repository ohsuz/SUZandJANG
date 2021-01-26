'''
[틀린 횟수] 多多
[원인] 범위 지정!!!!!!을 안해줬다
이동하려는 곳이 배열의 범위(0과 100001 사이) 안에 있어야만 연산을 수행해줘야한다
이놈의 범위...,,,
'''

from collections import deque

N, K = map(int, input().split())
d = [0] * 100001
queue = deque([N])

while queue and d[K] == 0 and K != N:
  cur = queue.popleft()
  if cur-1 >= 0:
    if d[cur-1] == 0:
      d[cur-1] = d[cur] + 1
      queue.append(cur-1)
    elif d[cur-1] > d[cur] + 1:
      d[cur-1] = d[cur] + 1
      queue.append(cur-1)
  if cur+1 <= 100000:
    if d[cur+1] == 0:
      d[cur+1] = d[cur] + 1
      queue.append(cur+1)
    elif d[cur+1] > d[cur] + 1:
      d[cur+1] = d[cur] + 1
      queue.append(cur+1)
  if cur*2 <= 100000:
    if d[cur*2] == 0:
      d[cur*2] = d[cur] + 1
      queue.append(cur*2)
    elif d[cur*2] > d[cur] + 1:
      d[cur*2] = d[cur] + 1
      queue.append(cur*2)

print(d[K])