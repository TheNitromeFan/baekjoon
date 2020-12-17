import sys
import collections


def traverse(adj, dq, visited):
    while dq:
        program = dq.popleft()
        for v in adj[program]:
            if not visited[v]:
                dq.append(v)
                visited[v] = True


def main():
    n = int(sys.stdin.readline())
    adj = {}
    dq = collections.deque()
    visited = {}
    for _ in range(n):
        program, x = sys.stdin.readline().split()
        if program not in adj:
            adj[program] = []
            visited[program] = False
        if program.split("::")[1] == "PROGRAM":
            dq.append(program)
            visited[program] = True
        programs = sys.stdin.readline().rstrip().split()
        for i in range(int(x)):
            identifier = programs[i]
            if identifier in adj:
                adj[identifier].append(program)
            else:
                adj[identifier] = [program]
                visited[identifier] = False
    traverse(adj, dq, visited)
    print(len([program for program in adj if not visited[program]]))


main()
