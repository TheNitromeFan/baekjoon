import sys
import string


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        s = sys.stdin.readline().rstrip()
        if "lol" in s:
            ans = 0
        elif "lo" in s or "ol" in s or "ll" in s or any("l" + x + "l" in s for x in string.ascii_lowercase):
            ans = 1
        elif "l" in s or "o" in s:
            ans = 2
        else:
            ans = 3
        sys.stdout.write("{}\n".format(ans))


main()
