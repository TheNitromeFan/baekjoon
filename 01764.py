def main():
    n, m = (int(x) for x in input().split())
    set1 = set()
    for _ in range(n):
        set1.add(input())
    set2 = set()
    for _ in range(m):
        set2.add(input())
    set3 = set.intersection(set1, set2)
    print(len(set3))
    print("\n".join(sorted(set3)))


main()
