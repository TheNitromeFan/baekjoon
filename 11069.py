import sys
import math
import itertools


def extended_gcd(a, b):
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a:
        (q, a), b = divmod(b, a), a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0


def crt(a1, m1, a2, m2):
    # print(a1, m1, a2, m2, end=" ")
    a3, m3, a4, m4 = a1, 1, a2, 1
    g = math.gcd(m1, m2)
    for prime in range(2, g + 1):
        if m1 % prime == m2 % prime == 0:
            cnt1, cnt2 = 0, 0
            while m1 % prime == 0:
                cnt1 += 1
                m1 //= prime
            while m2 % prime == 0:
                cnt2 += 1
                m2 //= prime
            if (a2 - a1) % prime ** min(cnt1, cnt2) != 0:
                return math.inf
            if cnt1 >= cnt2:
                m3 *= prime ** cnt1
            else:
                m4 *= prime ** cnt2
    _, inv1, _ = extended_gcd(m2 * m3 * m4, m1)
    _, inv2, _ = extended_gcd(m1 * m3 * m4, m2)
    _, inv3, _ = extended_gcd(m1 * m2 * m4, m3)
    _, inv4, _ = extended_gcd(m1 * m2 * m3, m4)
    # t = (a1 * inv1 * m2 * m3 * m4 + a2 * inv2 * m1 * m3 * m4 + a1 * inv3 * m1 * m2 * m4 + a2 * inv4 * m1 * m2 * m3) \
    #    % (m1 * m2 * m3 * m4)
    # print(t)
    return (a1 * inv1 * m2 * m3 * m4 + a2 * inv2 * m1 * m3 * m4 + a1 * inv3 * m1 * m2 * m4 + a2 * inv4 * m1 * m2 * m3) \
        % (m1 * m2 * m3 * m4)


def collision_time(w, h, x0, y0, x1, y1, a, b):
    ret = math.inf
    for x, y in itertools.product([x1, 2 * w - x1], [y1, 2 * h - y1]):
        g1 = math.gcd(2 * w, a)
        if (x - x0) % g1 != 0:
            continue
        g2 = math.gcd(2 * h, b)
        if (y - y0) % g2 != 0:
            continue
        ap, xp, wp = a // g1, (x - x0) // g1, 2 * w // g1
        bp, yp, hp = b // g2, (y - y0) // g2, 2 * h // g2
        _, t1, _ = extended_gcd(ap, wp)
        t1 *= xp
        t1 %= wp
        _, t2, _ = extended_gcd(bp, hp)
        t2 *= yp
        t2 %= hp
        ret = min(ret, crt(t1, wp, t2, hp))
    return ret


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        w, h, x0, y0, x1, y1, x2, y2, a, b = (int(x) for x in sys.stdin.readline().split())
        g = math.gcd(a, b)
        a, b = a // g, b // g
        a %= 2 * w
        b %= 2 * h
        cmp1, cmp2 = collision_time(w, h, x0, y0, x1, y1, a, b), collision_time(w, h, x0, y0, x2, y2, a, b)
        # print(cmp1, cmp2)
        if cmp1 < cmp2:
            print("A")
        elif cmp1 > cmp2:
            print("B")
        else:
            print("O")


main()
