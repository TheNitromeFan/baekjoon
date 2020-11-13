import sys


def main():
    n = int(sys.stdin.readline())
    for a0 in range(1, n + 1):
        s = int(sys.stdin.readline())
        engines = []
        for _ in range(s):
            engines.append(sys.stdin.readline().rstrip())
        q = int(sys.stdin.readline())
        searches = set()
        switches = 0
        for _ in range(q):
            term = sys.stdin.readline().rstrip()
            if term in searches:
                continue
            if len(searches) < s - 1:
                searches.add(term)
            else:
                switches += 1
                searches = {term}
        print("Case #{}: {}".format(a0, switches))


main()
