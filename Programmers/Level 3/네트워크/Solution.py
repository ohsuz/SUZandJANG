def solution(n, computers):
    answer = 0
    network = [[] for _ in range(n)]
    visited = [False] * n

    for i in range(len(computers)):
        for j in range(len(computers[0])):
            if computers[i][j] == 1 and i != j:
                network[i].append(j)             
    for i in range(n):
        if dfs(i, network, visited):
            answer += 1
    return answer

def dfs(com, network, visited):
    if visited[com]:
        return False
    visited[com] = True
    for i in network[com]:
        dfs(i, network, visited)
    return True
