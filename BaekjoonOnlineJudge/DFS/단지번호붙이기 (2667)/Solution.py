n = int(input())

graph = []
for i in range(n):
  graph.append(list(map(int, input())))


def dfs(x, y, cnt):
  if x <= -1 or x >= n or y <= -1 or y >= n:
    return False
  if graph[x][y] == 1:
    graph[x][y] = 0
    cnt += 1
    cnt += dfs(x-1, y, 0)
    cnt += dfs(x, y-1, 0)
    cnt += dfs(x+1, y, 0)
    cnt += dfs(x, y+1, 0)
    return cnt
  return cnt


total_village = 0
villages = []

for i in range(n):
  for j in range(n):
    result = dfs(i, j, 0)
    if result != 0:
      total_village += 1
      villages.append(result)

print(total_village)
for village in sorted(villages):
  print(village)
