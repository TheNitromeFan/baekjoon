from bisect import bisect_left, bisect_right
import sys


def main():
    primes = prime_sieve(10**6)
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        p = tuple(int(x) for x in sys.stdin.readline().split())
        s = solve(p, primes)
        sys.stdout.write(f"Case #{a0}: {s}\n")


def solve(problem, primes):
    A, B, P = problem
    union, find = mk_union_find_domain(range(A, B + 1))
    for i in range(bisect_left(primes, P), bisect_right(primes, B - A + 1)):
        p = primes[i]
        start = (A // p) * p
        if start < A:
            start += p
        for i in range(start + p, B + 1, p):
            union(i, start)
    return len(set(find(i) for i in range(A, B + 1)))


def prime_sieve(n):
    candidates = [True] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if candidates[i]:
            primes.append(i)
            for j in range(i + i, n + 1, i):
                candidates[j] = False
    return primes


def mk_union_find_domain(elems):
    d = dict((e, e) for e in elems)
    r = dict((e, 1) for e in elems)

    def union(u, v):
        urep = find(u)
        vrep = find(v)
        if urep != vrep:
            rank_diff = r[urep] - r[vrep]
            if rank_diff < 0:
                d[urep] = vrep
            else:
                d[vrep] = urep
                if rank_diff == 0:
                    r[urep] += 1

    def find(u):
        urep = d[u]
        if urep != u:
            urep = d[u] = find(urep)
        return urep
    return union, find


if __name__ == '__main__':
    main()
