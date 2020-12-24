import sys


def count_odd_digits(n):
    ret = 0
    for c in n:
        if c in "13579":
            ret += 1
    return ret


def odd_sums(n):
    ret = count_odd_digits(n)
    if len(n) == 1:
        return ret, ret
    elif len(n) == 2:
        minimum, maximum = odd_sums(str(int(n[0]) + int(n[1])))
        return ret + minimum, ret + maximum
    else:
        minimum, maximum = 100000000, 0
        for i in range(1, len(n)):
            for j in range(1, i):
                cmp1, cmp2 = odd_sums(str(int(n[:j]) + int(n[j:i]) + int(n[i:])))
                if minimum > cmp1:
                    minimum = cmp1
                if maximum < cmp2:
                    maximum = cmp2
        return ret + minimum, ret + maximum


def main():
    n = sys.stdin.readline().rstrip()
    a, b = odd_sums(n)
    print(a, b)


main()
