import sys


def main():
    n, m, d, s = (int(x) for x in sys.stdin.readline().split())
    drinks = []
    for _ in range(d):
        p, milk, t = (int(x) for x in sys.stdin.readline().split())
        drinks.append((p, milk, t))
    spoiled = set(range(1, m + 1))
    for _ in range(s):
        p, t = (int(x) for x in sys.stdin.readline().split())
        s1 = set()
        for p1, milk, t1 in drinks:
            if p == p1 and t1 < t:
                s1.add(milk)
        spoiled = spoiled & s1
    # print(spoiled)
    max_injured = 0
    for milk in spoiled:
        injured = set()
        for p1, milk1, t1 in drinks:
            if milk == milk1:
                injured.add(p1)
        if len(injured) > max_injured:
            max_injured = len(injured)
    print(max_injured)


main()
