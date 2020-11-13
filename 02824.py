import math


def product(list1):
    ret = 1
    for item in list1:
        ret *= item
    return ret


def main():
    input()
    a = product([int(x) for x in input().split()])
    input()
    b = product([int(x) for x in input().split()])
    ans = str(math.gcd(a, b))
    if len(ans) > 9:
        print(ans[-9:])
    else:
        print(ans)


main()
