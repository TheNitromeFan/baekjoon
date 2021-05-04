import sys


def main():
    n = int(sys.stdin.readline())
    strings = []
    for _ in range(n):
        s = sys.stdin.readline().rstrip()
        strings.append(s)
    bottleneck = min(strings, key=len)
    for length in range(len(bottleneck), -1, -1):
        for start in range(len(bottleneck) - length + 1):
            end = start + length
            t = bottleneck[start:end]
            if all(t in s for s in strings):
                print(length)
                return


main()
