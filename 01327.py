import sys
import collections
import string


def flips(s, n, k):
    dq = collections.deque()
    visited = {}
    dq.append(s)
    visited[s] = 0
    while dq:
        perm = dq.popleft()
        if perm == string.digits[1:n + 1]:
            return visited[perm]
        for i in range(n - k + 1):
            new_perm = perm[:i] + perm[i:i + k][::-1] + perm[i + k:]
            if new_perm not in visited:
                dq.append(new_perm)
                visited[new_perm] = visited[perm] + 1
    return -1


def main():
    n, k = (int(x) for x in sys.stdin.readline().split())
    s = sys.stdin.readline().rstrip().replace(" ", "")
    print(flips(s, n, k))


main()
