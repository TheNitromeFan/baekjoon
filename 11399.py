def main():
    n = int(input())
    p = [int(x) for x in input().split()]
    p.sort(reverse=True)
    print(sum(ind*val for ind, val in enumerate(p, start=1)))


main()
