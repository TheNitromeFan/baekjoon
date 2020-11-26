import sys


def remainder_by_11(n):
    rem = 0
    for i, c in enumerate(n[::-1]):
        if i % 2 == 0:
            rem += int(c)
        else:
            rem -= int(c)
    return rem % 11


def divide_by_11(n):
    ret = "0"
    cur = 0
    for c in n:
        cur = cur * 10 + int(c)
        ret += str(cur // 11)
        cur %= 11
    return ret.lstrip("0")


def phone(n):
    r = remainder_by_11(n)
    if r == 0:
        return "IMPOSSIBLE"
    if len(n) % 2 == 0:
        m = str(11 - r) + n
    else:
        m = str(r) + n
    ret = divide_by_11(m)
    if len(ret) == len(n):
        return ret
    else:
        return "IMPOSSIBLE"


def main():
    test = 0
    while True:
        s = sys.stdin.readline().rstrip()
        if s == "0":
            break
        test += 1
        sys.stdout.write("{}. {}\n".format(test, phone(s)))


main()
