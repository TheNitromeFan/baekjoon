def dfs(vertices, edges, start):
    stack = [start]
    visited = {vertex: False for vertex in vertices}
    result = []
    while stack:
        current = stack.pop()
        if visited[current]:
            continue
        temp_stack = []
        for edge in edges:
            if current in edge:
                other_vertex = list(edge.difference({current}))[0]
                if not visited[other_vertex]:
                    temp_stack.append(other_vertex)
        stack += sorted(temp_stack, reverse=True)
        visited[current] = True
        result.append(current)
    return result


def bfs(vertices, edges, start):
    queue = [start]
    visited = {vertex: False for vertex in vertices}
    result = []
    while queue:
        current = queue.pop(0)
        if visited[current]:
            continue
        temp_queue = []
        for edge in edges:
            if current in edge:
                new_vertex = list(edge.difference({current}))[0]
                if not visited[new_vertex]:
                    temp_queue.append(new_vertex)
        queue += sorted(temp_queue)
        visited[current] = True
        result.append(current)
    return result


def main():
    n, m, v = (int(x) for x in input().split())
    vertices = list(range(1, n+1))
    edges = []
    for _ in range(m):
        a, b = (int(x) for x in input().split())
        edges.append({a, b})
    print(" ".join(str(x) for x in dfs(vertices, edges, v)))
    print(" ".join(str(x) for x in bfs(vertices, edges, v)))


main()
