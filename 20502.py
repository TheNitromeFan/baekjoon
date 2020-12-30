import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    rank = [0] + [int(x) for x in sys.stdin.readline().split()]
    keywords = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        keywords[i] = [int(x) for x in sys.stdin.readline().split()[1:]]
    q = int(sys.stdin.readline())
    for _ in range(q):
        keyword = int(sys.stdin.readline())
        pages = [x for x in range(1, n + 1) if keyword in keywords[x]]
        pages.sort(key=lambda x: rank[x])
        if pages:
            print(" ".join(str(x) for x in pages))
        else:
            print(-1)


main()
