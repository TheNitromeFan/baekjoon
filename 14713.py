import sys
import collections


def reconstruct(parrots, n, s):
    words = []
    for parrot in parrots:
        dq = collections.deque()
        for word in parrot:
            dq.append(word)
        words.append(dq)
    for si in s:
        found = False
        for dq in words:
            if dq and dq[0] == si:
                dq.popleft()
                found = True
                break
        if not found:
            return False
    return not any(dq for dq in words)


def main():
    n = int(sys.stdin.readline())
    parrots = []
    for _ in range(n):
        parrots.append(sys.stdin.readline().rstrip().split())
    s = sys.stdin.readline().rstrip().split()
    if reconstruct(parrots, n, s):
        sys.stdout.write("Possible")
    else:
        sys.stdout.write("Impossible")


main()
