import sys
sys.setrecursionlimit(10000)

def dfs(user_map, x, y):
  if x <= -1 or x >= h or y <= -1 or y >= w:
    return False
  if user_map[x][y] == 0:
    return False
  user_map[x][y] = 0
  dfs(user_map, x+1, y)
  dfs(user_map, x-1, y)
  dfs(user_map, x, y+1)
  dfs(user_map, x, y-1)
  dfs(user_map, x+1, y+1)
  dfs(user_map, x+1, y-1)
  dfs(user_map, x-1, y+1)
  dfs(user_map, x-1, y-1)
  return True


w, h = map(int, input().split())
result = []

while [w, h] != [0, 0]:
  user_map= []
  for _ in range(h):
    user_map.append(list(map(int, sys.stdin.readline().split())))
  cnt = 0
  for i in range(h):
    for j in range(w):
      if dfs(user_map, i, j) == True:
        cnt += 1
  result.append(cnt)
  w, h = map(int, input().split())

print(*result, sep='\n')
