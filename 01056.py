import collections


def dijkstra(n):
    dq = collections.deque()
    dq.append((1, 0))
    while True:
        v, i = dq.popleft()
        if v == n:
            return i
        dq.append((v + 1, i + 1))
        if v > 1:
            dq.append((v - 1, i + 1))
            x = 1
            while v ** x <= n:
                x += 1
                dq.append((v ** x, i + 1))


def main():
    n = int(input())
    print(dijkstra(n))


main()
