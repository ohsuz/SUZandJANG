from collections import deque

M, N = map(int, input().split())
tomatoes = [list(map(int, input().split())) for _ in range(N)]
riped = deque([(i, j) for i in range(N) for j in range(M) if tomatoes[i][j] == 1])

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(riped):
  if 0 not in [t for tomato in tomatoes for t in tomato]: # 처음부터 모든 토마토가 익은 상태
    return 0
  day, day_seperator, riped_cnt = 0, len(riped), 0
  while riped:
    x, y = riped.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < N and 0 <= ny < M and tomatoes[nx][ny] == 0:
        riped_cnt += 1
        tomatoes[nx][ny] = 1 if day == 0 else tomatoes[x][y] + 1
        riped.append((nx, ny))
    if day_seperator > 0:
      day_seperator -= 1
    if day_seperator == 0 and riped:
      day_seperator, riped_cnt = riped_cnt, 0
      day += 1
  if -1 in [-1 for tomato in tomatoes for t in tomato if t == 0]: # 토마토가 모두 익지는 못하는 상황
    return -1
  return day

print(bfs(riped))

'''
으하하하하하하하하하하하하핳
'''
