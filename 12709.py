import sys
import itertools


def consecutive_groups(s):
    ret = 0
    idx = 0
    while idx < len(s):
        ret += 1
        start = idx
        while idx < len(s) and s[idx] == s[start]:
            idx += 1
    return ret


def main():
    n = int(sys.stdin.readline())
    for a0 in range(1, n + 1):
        k = int(sys.stdin.readline())
        s = sys.stdin.readline().rstrip()
        ans = len(s)
        for p in itertools.permutations(range(k)):
            t = ""
            for i in range(len(s)):
                t += s[i // k * k + p[i % k]]
            ans = min(ans, consecutive_groups(t))
        sys.stdout.write("Case #{}: {}\n".format(a0, ans))


main()
