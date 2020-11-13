for coordinate in sorted(tuple(int(x) for x in input().split()[::-1]) for i in range(int(input()))):
    print(" ".join(str(a) for a in coordinate[::-1]))
