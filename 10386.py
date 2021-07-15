import sys
import math


def partial_to_fraction(list1):
    if len(list1) == 1:
        return list1[0], 1
    n, d = 1, list1[-1]
    for x in list1[1:-1][::-1]:
        n, d = d, n + x * d
    n += d * list1[0]
    return n, d


def fraction_to_partial(n, d):
    q, r = divmod(n, d)
    ret = [q]
    if r == 0:
        return ret
    n = r
    while n != 1:
        n, d = d, n
        ret.append(n // d)
        n %= d
    ret.append(d)
    return ret


def main():
    t = 0
    while True:
        n, m = (int(x) for x in sys.stdin.readline().split())
        if n == m == 0:
            break
        t += 1
        a1 = [int(x) for x in sys.stdin.readline().split()]
        b1 = [int(x) for x in sys.stdin.readline().split()]
        print(f"Case {t}:")
        n1, d1 = partial_to_fraction(a1)
        n2, d2 = partial_to_fraction(b1)
        n3, d3 = n1 * d2 + n2 * d1, d1 * d2
        g = math.gcd(n3, d3)
        n3 //= g
        d3 //= g
        print(" ".join(str(x) for x in fraction_to_partial(n3, d3)))
        n3, d3 = n1 * d2 - n2 * d1, d1 * d2
        g = math.gcd(n3, d3)
        n3 //= g
        d3 //= g
        print(" ".join(str(x) for x in fraction_to_partial(n3, d3)))
        n3, d3 = n1 * n2, d1 * d2
        g = math.gcd(n3, d3)
        n3 //= g
        d3 //= g
        print(" ".join(str(x) for x in fraction_to_partial(n3, d3)))
        n3, d3 = n1 * d2, d1 * n2
        g = math.gcd(n3, d3)
        n3 //= g
        d3 //= g
        if d3 < 0:
            n3 *= -1
            d3 *= -1
        print(" ".join(str(x) for x in fraction_to_partial(n3, d3)))


main()
