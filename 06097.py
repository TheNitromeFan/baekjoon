def exp(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        m = exp(n, p // 2)
        return m * m
    else:
        m = exp(n, p // 2)
        return m * m * n


def main():
    n, p = (int(x) for x in input().split())
    s = str(exp(n, p))
    for i in range(0, len(s), 70):
        print(s[i:i+70])


main()
