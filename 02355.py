def main():
    a, b = (int(x) for x in input().split())
    if a > b:
        a, b = b, a
    if a >= 0:
        print(b * (b+1) // 2 - (a-1) * a // 2)
    elif b <= 0:
        a, b = -a, -b
        print(-(a * (a+1) // 2 - (b-1) * b // 2))
    else:
        a = -a
        if a <= b:
            print(b * (b+1) // 2 - a * (a+1) // 2)
        else:
            print(-(a * (a+1) // 2 - b*(b+1) // 2))


main()
