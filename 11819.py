def power(a, b, c):
    if b == 0:
        return 1 % c
    elif b % 2 == 0:
        p = power(a, b // 2, c)
        return p * p % c
    else:
        p = power(a, b // 2, c)
        return p * p * a % c


def main():
    a, b, c = (int(x) for x in input().split())
    print(power(a, b, c))


main()
