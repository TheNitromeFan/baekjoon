import sys
import itertools


def main():
    n = int(sys.stdin.readline())
    b = [int(x) for x in sys.stdin.readline().split()]
    b.sort()
    bad_triples = []
    bad_elements = set()
    for i in range(n):
        for j in range(i):
            for k in range(j):
                if b[k] + b[j] <= b[i]:
                    bad_triples.append({k, j, i})
                    bad_elements.add(k)
                    bad_elements.add(j)
                    bad_elements.add(i)
    if not bad_elements:
        print(n)
        return
    for i in range(1, len(bad_elements) + 1):
        for x in itertools.combinations(bad_elements, i):
            elements = set(x)
            if all(triple & elements for triple in bad_triples):
                print(n - i)
                return


main()
