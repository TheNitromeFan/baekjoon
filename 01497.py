import sys
import itertools


def minimum_guitars(guitars, n, m):
    max_songs = 0
    ans = 0
    for i in range(1, n + 1):
        for c in itertools.combinations(guitars, i):
            x = sum(any(guitar[j] == "Y" for guitar in c) for j in range(m))
            if x > max_songs:
                max_songs = x
                ans = i
    if max_songs:
        return ans
    else:
        return -1


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    guitars = []
    for _ in range(n):
        yesno = sys.stdin.readline().rstrip().split()[1]
        guitars.append(yesno)
    print(minimum_guitars(guitars, n, m))


main()
