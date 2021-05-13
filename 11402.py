import sys
import math


def p_expansion(n, p):
    ret = []
    while n:
        ret.append(n % p)
        n //= p
    return ret


def main():
    n, k, m = (int(x) for x in sys.stdin.readline().split())
    np, kp = p_expansion(n, m), p_expansion(k, m)
    kp += [0] * (len(np) - len(kp))
    ans = 1
    for ni, ki in zip(np, kp):
        ans *= math.comb(ni, ki)
        ans %= m
    print(ans)


main()
