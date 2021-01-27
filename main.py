'''
수지의 Replit 연습장
'''
N = input()
sets = ['0123456789' for _ in range(len(N))]
index, cnt = [0 for _ in range(10)], [0 for _ in range(10)]

for num in N:
  i = index[int(num)]
  if num in sets[i]:
    sets[i] = sets[i].replace(num, '')
    cnt[int(num)] += 1
    if num not in '69':
      index[int(num)] += 1
  else:
    if num == '6' and '9' in sets[i]:
      sets[i] = sets[i].replace('9', '')
      cnt[9] += 1
      index[6] += 1
      index[9] += 1
    elif num == '9' and '6' in sets[i]:
      sets[i] = sets[i].replace('6', '')
      cnt[6] += 1
      index[6] += 1
      index[9] += 1
    else:
      sets[i+1] = sets[i+1].replace(num, '')
      cnt[int(num)] += 1
      index[int(num)] += 1

print(max(cnt))













'''
from collections import deque
# N = int(input())
# graph = [list(map(int, input()) for _ in range(N)]
answer = []
n = 7
graph = [[0,1,1,0,1,0,0],
[0,1,1,0,1,0,1],
[1,1,1,0,1,0,1],
[0,0,0,0,1,1,1],
[0,1,0,0,0,0,0],
[0,1,1,1,1,1,0],
[0,1,1,1,0,0,0]]

visited = [[0] * n for _ in range(n)]

dx = [-1, -1, 1, 1]
dy = [1, -1, 1, -1]

def bfs(x, y):
  if visited[x][y] != 0: # 이미 방문했음
    return 0
  queue = deque()
  queue.append((x, y))
  move = 1
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx < 0 or nx >= n or ny < 0 or ny >= n or graph[nx][ny] == 0 or visited[nx][ny] != 0:
        continue
      if visited[nx][ny] == 0 and graph[nx][ny] == 1:
        visited[nx][ny] = 1
        queue.append((nx, ny))
        move += 1
  return move

for i in range(n):
  for j in range(n):
    result = bfs(i, j)
    if result != 0:
      answer.append(result)

print(len(answer))
print(*sorted(answer), sep='\n')
'''