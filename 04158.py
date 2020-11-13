import sys


while True:
    n, m = (int(x) for x in sys.stdin.readline().rstrip().split())
    if n == 0 and m == 0:
        break
    set1, set2 = set(), set()
    for _ in range(n):
        set1.add(int(sys.stdin.readline()))
    for _ in range(m):
        set2.add(int(sys.stdin.readline()))
    print(len(set1.intersection(set2)))
