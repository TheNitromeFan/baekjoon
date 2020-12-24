import sys


def main():
    t = 0
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        t += 1
        nodes = {}
        for _ in range(n):
            cube = [int(w) for w in sys.stdin.readline().split()]
            cube.sort(reverse=True)
            x, y, z = cube
            nodes[(x, y)] = z
            nodes[(x, z)] = y
            nodes[(y, z)] = x
        adj = {}
        indegree = {node: 0 for node in nodes}
        for node1 in nodes:
            adj[node1] = []
            for node2 in nodes:
                if node1[0] > node2[0] and node1[1] > node2[1]:
                    adj[node1].append(node2)
                    indegree[node2] += 1
        dp = {node: 0 for node in nodes}
        while nodes:
            node1 = min(nodes, key=lambda x: indegree[x])
            dp[node1] = 0
            for node2 in adj:
                if node1 in adj[node2]:
                    dp[node1] = max(dp[node1], dp[node2])
                    indegree[node2] -= 1
            dp[node1] += nodes[node1]
            del nodes[node1]
        print("Case {}: maximum height = {}".format(t, max(dp.values())))


main()
