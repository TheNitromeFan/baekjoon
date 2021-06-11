import sys
import collections


def bfs(adj, erdos):
    q = collections.deque()
    q.append("Erdos, P.")
    erdos["Erdos, P."] = 0
    while q:
        u = q.popleft()
        for v in adj[u]:
            if erdos[v] == float("inf"):
                q.append(v)
                erdos[v] = erdos[u] + 1


def main():
    t = 0
    while True:
        p, n = (int(x) for x in sys.stdin.readline().split())
        if p == n == 0:
            break
        t += 1
        adj = {}
        for _ in range(p):
            paper = sys.stdin.readline().rstrip()
            authors, title = paper.split(": ")
            names = authors.split(", ")
            author_list = []
            for i in range(0, len(names), 2):
                author = names[i] + ", " + names[i + 1]
                if author not in adj:
                    adj[author] = []
                author_list.append(author)
            for i in range(len(author_list)):
                for j in range(i):
                    adj[author_list[i]].append(author_list[j])
                    adj[author_list[j]].append(author_list[i])
        erdos = {x: float("inf") for x in adj}
        bfs(adj, erdos)
        print(f"Database #{t}")
        for _ in range(n):
            person = sys.stdin.readline().rstrip()
            if person not in erdos or erdos[person] == float("inf"):
                print(f"{person}: infinity")
            else:
                print(f"{person}: {erdos[person]}")
        print()


main()
