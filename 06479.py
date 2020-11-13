from math import factorial


def right_justified(n):
    n = str(n)
    return " " * (5-len(n)) + n


def factorial_frequencies(n):
    fn = factorial(n)
    counts = {x: 0 for x in range(10)}
    while fn:
        counts[fn % 10] += 1
        fn //= 10
    return counts


def main():
    while True:
        n = input()
        if not n:
            continue
        n = int(n)
        if n == 0:
            break
        counts = factorial_frequencies(n)
        print("{}! --".format(n))
        for i in range(5):
            print("   ({}){} ".format(i, right_justified(counts[i])), end="")
        print()
        for i in range(5, 10):
            print("   ({}){} ".format(i, right_justified(counts[i])), end="")
        print()


main()
