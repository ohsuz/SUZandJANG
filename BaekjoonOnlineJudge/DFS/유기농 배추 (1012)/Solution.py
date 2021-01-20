import sys
sys.setrecursionlimit(10000)

def dfs(x, y):
  if x <= -1 or x >= N or y <= -1 or y >= M:
    return False
  if field[x][y] == 0:
    return False
  field[x][y] = 0
  dfs(x+1, y)
  dfs(x, y+1)
  dfs(x-1, y)
  dfs(x, y-1)
  return True


result = []
cases = int(input())

for _ in range(cases):
  M, N, K = map(int, input().split())
  field = [[0]*M for _ in range(N)]
  for _ in range(K):
    a, b = map(int, sys.stdin.readline().split())
    field[b][a] = 1
  cnt = 0
  for i in range(N):
    for j in range(M):
      if dfs(i, j) == True:
        cnt += 1
  result.append(cnt)

print(*result, sep='\n')
