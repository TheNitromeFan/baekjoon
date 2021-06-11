import sys
import fractions


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    w = [abs(int(x)) for x in sys.stdin.readline().split()]
    w.sort(reverse=True)
    w_squared = [x ** 2 for x in w]
    min_dist = sum(w_squared) - fractions.Fraction(sum(w) ** 2, n)
    if min_dist.denominator == 1:
        print(f"{min_dist}/1")
    else:
        print(min_dist)
