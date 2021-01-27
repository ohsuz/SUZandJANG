'''
1로 만들기 문제완 다르게 재방문 시 값을 더 작은 걸로 교체해주지 않아도 문제가 통과한다
각자 가는 방향과 속도가 1로 만들기 문제보다 차이가 크니까 연산이 겹칠 일이 없나??
'''

from collections import deque

N, K = map(int, input().split())
d = [0] * 100001
queue = deque([N])

while not d[K] and K != N:
  cur = queue.popleft()
  if cur-1 >= 0 and d[cur-1] == 0:
    d[cur-1] = d[cur] + 1
    queue.append(cur-1)
  if cur+1 <= 100000 and d[cur+1] == 0:
    d[cur+1] = d[cur] + 1
    queue.append(cur+1)
  if cur*2 <= 100000 and d[cur*2] == 0:
    d[cur*2] = d[cur] + 1
    queue.append(cur*2)

print(d[K])