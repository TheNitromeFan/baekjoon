import sys


def main():
    n = int(sys.stdin.readline())
    notes1 = [int(x) for x in sys.stdin.readline().split()]
    m = int(sys.stdin.readline())
    notes2 = [int(x) for x in sys.stdin.readline().split()]
    ans = []
    for i in range((m - 1) // (n - 1) + 1):
        for k in range(m - (n - 1) * (i + 1) + 1):
            if notes2[k: k + (n - 1) * (i + 1) + 1: i + 1] == notes1:
                ans.append(i)
                break
    if ans:
        sys.stdout.write("{} {}".format(ans[0], ans[-1]))
    else:
        sys.stdout.write("-1")


main()
