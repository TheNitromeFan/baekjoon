import itertools


def main():
    time = [int(x) for x in input().split(":")]
    time_count = 0
    for d, m, h in itertools.permutations(time):
        if 1 <= d <= 12 and 0 <= m <= 59 and 0 <= h <= 59:
            time_count += 1
    print(time_count)


main()
