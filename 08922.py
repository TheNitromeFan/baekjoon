import sys


def next_tuple(t):
    ret = []
    for i in range(len(t) - 1):
        ret.append(abs(t[i + 1] - t[i]))
    ret.append(abs(t[0] - t[-1]))
    return tuple(ret)


def ducci(t):
    cache = set()
    while True:
        if not any(t):
            return "ZERO"
        elif t in cache:
            return "LOOP"
        cache.add(t)
        t = next_tuple(t)


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        sys.stdin.readline()
        t = tuple(int(x) for x in sys.stdin.readline().split())
        print(ducci(t))


main()
