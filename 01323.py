import sys


def main():
    n_str, k = sys.stdin.readline().split()
    n, m, k = int(n_str), len(n_str), int(k)
    x = n % k
    counter = 1
    remainders_seen = {x}
    while x != 0:
        x = x * 10 ** m + n
        x %= k
        if x in remainders_seen:
            print(-1)
            return
        remainders_seen.add(x)
        counter += 1
    print(counter)


main()
