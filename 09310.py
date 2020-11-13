def main():
    while True:
        n = int(input())
        if n == 0:
            break
        a, b, c = (int(x) for x in input().split())
        if 2 * b == a + c:
            d = b - a
            print(n * (2 * a + (n - 1) * d) // 2)
        else:
            r = b // a
            print(a * (r ** n - 1) // (r - 1))


main()
