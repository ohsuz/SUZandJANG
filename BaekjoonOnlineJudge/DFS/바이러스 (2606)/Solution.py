def dfs(graph, start, visited):
  if start not in visited:
    visited.append(start)
  else:
    return
  for node in graph[start]:
    dfs(graph, node, visited)
  return visited


com = int(input())
lines = int(input()) 
graph = [[] for i in range(com+1)]

for i in range(lines):
  a, b = map(int, input().split())
  graph[a].extend([b])
  graph[b].extend([a])

print(len(dfs(graph, 1, [])) - 1)