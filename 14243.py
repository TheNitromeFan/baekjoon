import sys


def schedule(s):
    a, b, c = s.count('A'), s.count('B'), s.count('C')
    n = a + b + c
    ret = ''
    while n > 0:
        if a >= 1 and b >= 2 and 1 <= c < (n + 2) // 3:
            ret += 'BCBA'
            a -= 1
            b -= 2
            c -= 1
            n -= 4
        elif a >= 1 and b >= 1 and c >= 1:
            ret += 'CBA'
            a -= 1
            b -= 1
            c -= 1
            n -= 3
        elif a >= 2 and b == 0 and c >= 1:
            ret += 'CAA'
            a -= 2
            c -= 1
            n -= 3
        elif a >= 1 and b >= 1:
            ret += 'BA'
            a -= 1
            b -= 1
            n -= 2
        elif a >= 1:
            ret += 'A'
            a -= 1
            n -= 1
        elif n == 1:
            if a == 1:
                ret += 'A'
                a -= 1
                n -= 1
            elif b == 1:
                ret += 'B'
                b -= 1
                n -= 1
            elif c == 1:
                ret += 'C'
                c -= 1
                n -= 1
            else:
                return '-1'
        elif n == 2:
            if b == 1 and c == 1:
                ret += 'CB'
                b -= 1
                c -= 1
                n -= 2
            elif a == 1 and c == 1:
                ret += 'CA'
                a -= 1
                c -= 1
                n -= 2
            else:
                return '-1'
        elif n == 3:
            if b == 2 and c == 1:
                ret += 'BCB'
                b -= 2
                c -= 1
                n -= 3
            else:
                return '-1'
        else:
            return '-1'
    return ret


def main():
    s = sys.stdin.readline().rstrip()
    sys.stdout.write(schedule(s))


main()
