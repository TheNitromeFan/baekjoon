import sys


def prime_factorization(n):
    ret = {}
    for p in range(2, int(n ** 0.5) + 1):
        if n % p != 0:
            continue
        ret[p] = 0
        while n % p == 0:
            ret[p] += 1
            n //= p
    if n > 1:
        ret[n] = 1
    return ret


def main():
    t = 0
    while True:
        a, b = (int(x) for x in sys.stdin.readline().split())
        if a == b == 0:
            break
        t += 1
        pa, pb = prime_factorization(a), prime_factorization(b)
        keys = set(pa.keys()) | set(pb.keys())
        dist = 0
        for key in keys:
            if key not in pa:
                pa[key] = 0
            if key not in pb:
                pb[key] = 0
            dist += abs(pa[key] - pb[key])
        print(f"{t}. {len(keys)}:{dist}")


main()
