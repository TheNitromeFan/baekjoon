def to_octal(n):
    ret = 0
    power_of_ten = 1
    while n:
        ret += power_of_ten * (n % 8)
        n //= 8
        power_of_ten *= 10
    return ret


def main():
    n = int(input(), base=16)
    print(to_octal(n))


main()
