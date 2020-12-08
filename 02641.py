import sys


def main():
    n = int(sys.stdin.readline())
    block = [int(x) for x in sys.stdin.readline().split()]
    matches = []
    for i in range(n):
        matches.append(block[i:] + block[:i])
    block1 = [(x + 1) % 4 + 1 for x in reversed(block)]
    for i in range(n):
        matches.append(block1[i:] + block1[:i])
    m = int(sys.stdin.readline())
    ans = []
    for _ in range(m):
        cmp = [int(x) for x in sys.stdin.readline().split()]
        if cmp in matches:
            ans.append(cmp)
    sys.stdout.write("{}".format(len(ans)))
    for seq in ans:
        sys.stdout.write("\n{}".format(" ".join(str(x) for x in seq)))


main()
