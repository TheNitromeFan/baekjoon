import sys


def paren(dp, n, k):
    if dp[(n, n)] < k:
        return "Doesn't Exist!"
    ret = ""
    a, b = n, n
    while a > 0 and b > 0:
        if dp[(a - 1, b)] >= k:
            ret += "("
            a -= 1
        else:
            k -= dp[(a - 1, b)]
            ret += ")"
            b -= 1
    while b > 0:
        ret += ")"
        b -= 1
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, k = (int(x) for x in sys.stdin.readline().split())
        dp = {}
        for j in range(n + 1):
            dp[(0, j)] = 1
        for i in range(1, n + 1):
            for j in range(n + 1):
                dp[(i, j)] = dp[(i - 1, j)]
                if i < j:
                    dp[(i, j)] += dp[(i, j - 1)]
        sys.stdout.write("Case #{}: {}\n".format(a0, paren(dp, n, k)))


main()
