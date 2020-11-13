def main():
    n = int(input())
    s = 0
    for _ in range(n):
        p = int(input())
        q, r = divmod(p, 10)
        s += q ** r
    print(s)


main()
