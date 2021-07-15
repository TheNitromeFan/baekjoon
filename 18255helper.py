import math
import itertools


def main():
    ans = [0]
    for n in range(1, 101):
        count = 0
        for a, b, c in itertools.product(range(n + 1), repeat=3):
            if math.gcd(a, b, c) == 1:
                count += 1
        ans.append(count)
        if n % 10 == 0:
            print(n)
    print(ans)


main()
