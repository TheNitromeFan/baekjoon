import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b = (int(x) for x in sys.stdin.readline().split())
        i, n = (int(x) for x in sys.stdin.readline().split())
        k, x = a % b, 10 % b
        i -= 1
        ans = ""
        while i:
            if i % 2:
                k = k * x % b
            x = x * x % b
            i //= 2
        while n:
            ans += str(k % b * 10 // b)
            k = k % b * 10 % b
            n -= 1
        print(ans)


main()
