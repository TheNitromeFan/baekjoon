def is_square(n):
    x = int(n ** 0.5)
    return n in [(x - 2) ** 2, (x - 1) ** 2, x ** 2, (x + 1) ** 2, (x + 2) ** 2]


def main():
    input()
    nums = [int(x) for x in input().split()]
    output = [int(is_square(x)) for x in nums]
    print(" ".join(str(x) for x in output))


main()
