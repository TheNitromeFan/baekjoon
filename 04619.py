while True:
    b, n = (int(x) for x in input().split())
    if b == n == 0:
        break
    a = int(b ** (1 / n))
    if (a + 1) ** n - b < b - a ** n:
        print(a + 1)
    else:
        print(a)
