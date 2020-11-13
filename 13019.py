def main():
    a = input()
    b = input()
    if sorted(a) != sorted(b):
        print("-1")
        return
    i2 = len(b) - 1
    ops = 0
    for i1 in range(len(a) - 1, -1, -1):
        if a[i1] == b[i2]:
            i2 -= 1
        else:
            ops += 1
    print(ops)


main()
