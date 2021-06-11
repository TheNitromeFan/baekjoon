import sys


def reversed_digits(n):
    ret = 0
    while n:
        ret *= 10
        ret += n % 10
        n //= 10
    return ret


def next_jump(n):
    return (10 ** ((n + 1) // 2 + 1) - 1) * (10 ** (n // 2 + 1) + 1)


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n = int(sys.stdin.readline())
        ans = 0
        current = 0
        order = 0
        while n >= next_jump(order):
            target = reversed_digits(next_jump(order))
            ans += target - current
            current = target
            ans += 1
            current = reversed_digits(current)
        if n > 10 ** (order + 1):
            high = n // (10 ** (order // 2 + 1))
            if n % (10 ** (order // 2 + 1)) == 0:
                high -= 1
            cnt = 10 ** (order + 1) + reversed_digits(high)
            ans += cnt - current
            current = cnt
            if current != reversed_digits(current):
                ans += 1
                current = reversed_digits(current)
        ans += n - current
        current = n
        print(f"Case #{a0}: {ans}")


main()
