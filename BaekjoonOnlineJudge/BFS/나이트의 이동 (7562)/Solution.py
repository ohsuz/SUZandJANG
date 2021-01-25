from collections import deque

answer = []


def bfs(x, y):
  dx = [-1, -1, -2, -2, 1, 1, 2, 2]
  dy = [-2, 2, -1, 1, -2, 2, -1, 1]
  queue = deque()
  queue.append((x, y))
  while queue:
    curx, cury = queue.popleft()
    if curx == goalx and cury == goaly:
      return board[curx][cury]
    for i in range(8):
      newx, newy = curx + dx[i], cury + dy[i]
      if newx < 0 or newy < 0 or newx >= I or newy >= I:
        continue
      if board[newx][newy] == 0:
        board[newx][newy] = board[curx][cury] + 1
        queue.append((newx, newy))


loop = int(input())
for l in range(loop):
  I = int(input())
  board = [[0] * I for _ in range(I)]
  fromx, fromy = map(int, input().split())
  goalx, goaly = map(int, input().split())
  answer.append(bfs(fromx, fromy))

print(*answer, sep='\n')