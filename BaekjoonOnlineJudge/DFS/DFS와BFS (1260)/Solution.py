from collections import deque


def bfs(graph, start, visited):
  visited.append(start)
  queue = deque(graph[start])

  while queue:
    cur = queue.popleft()
    visited.append(cur)
    for node in graph[cur]:
      if node not in visited and node not in queue:
        queue.append(node)
  
  return visited


def dfs(graph, start, visited):
  if start not in visited:
    visited.append(start)
  else:
    return
  for node in graph[start]:
    dfs(graph, node, visited)
  return visited


n, m, v = map(int, input().split())
graph = [[] for i in range(n+1)]

for i in range(1, m+1):
  a, b = map(int, input().split())
  graph[a].extend([b])
  graph[b].extend([a])

graph = list(map(sorted, graph))

print(' '.join(map(str,dfs(graph, v, []))))
print(' '.join(map(str, bfs(graph, v, []))))
