import sys


PRECISION = 1e6


def check(psum, f, i, j, min_y, min_x, ans):
    dy, dx = abs(psum[j] - psum[i]), abs(j - i)
    y, x = abs(dy * PRECISION - dx * f), dx * PRECISION
    if y * min_x < min_y * x:
        min_y, min_x, ans = y, x, min(i, j)
    elif y * min_x == min_y * x:
        ans = min(ans, i, j)
    return min_y, min_x, ans


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, f = sys.stdin.readline().rstrip().split()
        s = sys.stdin.readline().rstrip()
        n = int(n)
        f = int(float(f) * PRECISION)
        psum = [0] * (n + 1)
        for i in range(n):
            psum[i + 1] = psum[i]
            if s[i] == '1':
                psum[i + 1] += 1
        p = []
        for i in range(n + 1):
            p.append((psum[i] * PRECISION - i * f, i))
        p.sort()
        min_y, min_x, ans = 1, 1, n - 1
        for i in range(n):
            min_y, min_x, ans = check(psum, f, p[i][1], p[i + 1][1], min_y, min_x, ans)
        sys.stdout.write(f"Case #{a0}: {ans}\n")


main()
