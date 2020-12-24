import sys


ans = [0, 1]


def length_of_decimal(a, b):
    ret = len(str(a // b))
    a %= b
    if a == 0:
        return ret
    ret += 1
    remainders = {a}
    while True:
        a *= 10
        ret += 1
        a %= b
        if a == 0:
            return ret
        elif a in remainders:
            return ret + 2
        remainders.add(a)


def longest_decimal():
    for n in range(2, 501):
        ret = ans[n - 1]
        for a in range(1, n):
            cmp = length_of_decimal(a, n)
            if ret < cmp:
                ret = cmp
        for b in range(1, n):
            cmp = length_of_decimal(n, b)
            if ret < cmp:
                ret = cmp
        ans.append(ret)


def main():
    longest_decimal()
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        print(ans[n])


main()
