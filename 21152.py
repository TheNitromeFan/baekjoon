import sys


def cycle_length(adj, visited, start, current, counter):
    visited[current] = True
    ret = 0
    v = adj[current]
    if v == start:
        return counter
    elif v not in adj or visited[v]:
        return 0
    else:
        ret = max(ret, cycle_length(adj, visited, start, v, counter + 1))
    visited[current] = False
    return ret


def main():
    n = int(sys.stdin.readline())
    adj = {}
    for _ in range(n):
        name, has, wants = sys.stdin.readline().rstrip().split()
        adj[has] = wants
    visited = {x: False for x in adj}
    ans = 0
    for v in adj:
        if not visited[v]:
            ans = max(ans, cycle_length(adj, visited, v, v, 1))
    if ans:
        print(ans)
    else:
        print("No trades possible")


main()
