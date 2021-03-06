import sys
import decimal


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, x, k, a, b, c = (int(z) for z in sys.stdin.readline().split())
        i = 0
        ans = decimal.Decimal(0)
        while x or k:
            xk, kk = x % 2, k % 2
            t = {(0, 0): decimal.Decimal(0), (0, 1): decimal.Decimal(b + c) / 100,
                 (1, 0): decimal.Decimal(b + c) / 100, (1, 1): decimal.Decimal(a + b) / 100}
            p = decimal.Decimal(xk)
            for _ in range(n):
                p = p * t[(1, kk)] + (1 - p) * t[(0, kk)]
            # print(xk, kk, p)
            ans += p * 2 ** i
            x //= 2
            k //= 2
            i += 1
        sys.stdout.write("Case #{}: {}\n".format(a0, ans))


main()
