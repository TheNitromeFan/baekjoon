import sys


def main():
    ethnicities = {}
    population = 0
    for line in sys.stdin.readlines():
        if line in ethnicities:
            ethnicities[line] += 1
        else:
            ethnicities[line] = 1
        population += 1
    numerator, denominator = population ** 2, population ** 2
    for val in ethnicities.values():
        numerator -= val ** 2
    print(numerator / denominator)


main()
