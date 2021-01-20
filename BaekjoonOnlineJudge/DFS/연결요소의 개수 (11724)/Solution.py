import sys
sys.setrecursionlimit(10000)

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)
for _ in range(m):
  a, b = map(int, sys.stdin.readline().split())
  graph[a].append(b)
  graph[b].append(a)


def dfs(start):
  visited[start] = True
  for node in graph[start]:
    if not visited[node]:
      dfs(node)


result = 0
for i in range(1, n+1):
  if not visited[i]:
    dfs(i)
    result += 1
print(result)

'''
만나서 더러웠고 다신 보지말자^-^!
'''
