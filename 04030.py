import sys


def main():
    triangles = set()
    limit = 10 ** 9 + 7
    n = 1
    while True:
        triangle = n * (n + 1) // 2
        if triangle >= limit:
            break
        triangles.add(triangle)
        n += 1
    t = 0
    while True:
        a, b = (int(x) for x in sys.stdin.readline().split())
        if a == b == 0:
            break
        t += 1
        ans = 0
        for n in range(int(a ** 0.5), int(b ** 0.5) + 1):
            if a < n ** 2 < b and n ** 2 - 1 in triangles:
                ans += 1
        sys.stdout.write("Case {}: {}\n".format(t, ans))


main()
