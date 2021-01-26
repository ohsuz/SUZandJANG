from collections import deque

X = int(input())
memo = [0] * (X+1)
cur = deque([X])
while cur and memo[1] == 0:
  print(cur)
  c = cur.popleft()
  if c % 5 == 0 and memo[c//5] == 0:
    memo[c//5] = memo[c] + 1
    cur.append(c//5)
  if c % 3 == 0 and memo[c//3] == 0:
    memo[c//3] = memo[c] + 1
    cur.append(c//3)
  if c % 2 == 0:
    memo[c//2] = memo[c] + 1
    cur.append(c//2)
  if memo[c-1] == 0:
    memo[c-1] = memo[c] + 1
    cur.append(c-1)

print(memo[1])