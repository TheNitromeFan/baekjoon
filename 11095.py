import sys


def search(adj, visited, src, dest):
    if src == dest:
        return True
    for v in adj[src]:
        if not visited[v]:
            visited[v] = src
            if search(adj, visited, v, dest):
                return True
    return False


def main():
    n = int(sys.stdin.readline())
    adj = {}
    visited = {}
    lines = []
    for _ in range(n):
        stops = sys.stdin.readline().rstrip().split()
        for stop in stops:
            visited[stop] = None
            adj[stop] = set()
        lines.append(stops)
    for line in lines:
        adj[line[0]] |= set(line[1:])
        for stop in line[1:]:
            adj[stop].add(line[0])
    # print(adj)
    source, destination = sys.stdin.readline().rstrip().split()
    if source not in adj:
        adj[source] = set()
        visited[source] = None
    if destination not in adj:
        adj[destination] = set()
        visited[destination] = None
    visited[source] = True
    if search(adj, visited, source, destination):
        path = [destination]
        while destination != source:
            destination = visited[destination]
            path.append(destination)
        path.reverse()
        sys.stdout.write(" ".join(path))
    else:
        sys.stdout.write("no route found")


main()
