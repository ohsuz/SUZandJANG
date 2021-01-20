import copy
import sys
sys.setrecursionlimit(10000)

def dfs(province, rain, x, y):
  if x <= -1 or x >= N or y <= -1 or y >= N:
    return False
  if province[x][y] <= rain:
    return False
  province[x][y] = 0
  dfs(province, rain, x+1, y)
  dfs(province, rain, x-1, y)
  dfs(province, rain, x, y+1)
  dfs(province, rain, x, y-1)
  return True


N = int(input())
province = []
max_rain = 0

for _ in range(N):
  user_input = list(map(int, sys.stdin.readline().split()))
  max_rain = max(max_rain, max(user_input))
  province.append(user_input)

result = [1] # 강수량이 0일때의 경우를 미리 넣어둠
for rain in range(1, max_rain+1):
  cnt = 0
  temp = copy.deepcopy(province)
  for i in range(N):
    for j in range(N):
      if dfs(temp, rain, i, j) == True:
        cnt += 1
  result.append(cnt)

print(max(result))
