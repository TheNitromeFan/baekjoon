import sys
import itertools


good_nums = {x: {1} for x in range(2, 11)}
bad_nums = {x: set() for x in range(2, 11)}


def sum_of_squares_of_digits(n, base):
    ret = 0
    while n:
        ret += (n % base) ** 2
        n //= base
    return ret


def happy(n, base):
    seen = set()
    while True:
        if n in good_nums[base]:
            good_nums[base] |= seen
            return True
        elif n in bad_nums[base] or n in seen:
            bad_nums[base] |= seen
            return False
        seen.add(n)
        n = sum_of_squares_of_digits(n, base)


def happy_in_all_bases(bases, n):
    for base in bases:
        if happy(n, base):
            good_nums[base].add(n)
        else:
            bad_nums[base].add(n)
            return False
    return True


def main():
    bases = list(range(2, 11))
    with open("12650.txt", "w") as f:
        for length in range(1, 10):
            for subbases in itertools.combinations(bases, length):
                n = 2
                while not happy_in_all_bases(subbases, n):
                    n += 1
                f.write("{}: {}\n".format(subbases, n))
                print(subbases)


def main2():
    with open("12650.txt", "r") as f:
        ans = []
        for line in f:
            entries = line.split(":")
            bases, number = list(eval(entries[0])), int(entries[1])
            ans.append((bases, number))
    with open("12650ans.txt", "w") as g:
        g.write("{}".format(ans))


# main()
main2()
