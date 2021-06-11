import sys


def main():
    n, q = (int(x) for x in sys.stdin.readline().split())
    ans, min_cost = -1, 10 ** 1000
    for i in range(1, n + 1):
        p, k, c = (int(x) for x in sys.stdin.readline().split())
        intervals = q // k
        if q % k == 0:
            intervals -= 1
        cost = p + intervals * (intervals + 1) // 2 * c
        if cost < min_cost:
            ans, min_cost = i, cost
    print(ans, min_cost)


main()
