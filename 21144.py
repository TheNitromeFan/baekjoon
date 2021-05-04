import sys


def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().rstrip()
    idx = 0
    m = 1
    while idx < len(s):
        p = str(m)
        length = len(p)
        if s[idx:idx+length] != p:
            print(p)
            return
        idx += length
        m += 1
    print(n)
    return


main()
