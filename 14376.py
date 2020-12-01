import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        s = sys.stdin.readline().rstrip()
        ans = ""
        for c in s:
            ans = max(ans + c, c + ans)
        sys.stdout.write("Case #{}: {}\n".format(a0, ans))


main()
