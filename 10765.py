import sys


def main():
    n = int(sys.stdin.readline())
    letter_counts = {x: [0, 0] for x in "BESSIEGOESMOO"}
    for _ in range(n):
        letter, count = sys.stdin.readline().rstrip().split()
        letter_counts[letter][int(count) % 2] += 1
    combinations = 1
    for letter, values in letter_counts.items():
        combinations *= values[0] + values[1]
    odd_combinations = 1
    odd_combinations *= letter_counts["B"][0] * letter_counts["I"][1] + letter_counts["B"][1] * letter_counts["I"][0]
    goes = 0
    goes += letter_counts["G"][0] * letter_counts["O"][0] * letter_counts["E"][0] * letter_counts["S"][1]
    goes += letter_counts["G"][0] * letter_counts["O"][0] * letter_counts["E"][1] * letter_counts["S"][0]
    goes += letter_counts["G"][0] * letter_counts["O"][1] * letter_counts["E"][0] * letter_counts["S"][0]
    goes += letter_counts["G"][1] * letter_counts["O"][0] * letter_counts["E"][0] * letter_counts["S"][0]
    goes += letter_counts["G"][0] * letter_counts["O"][1] * letter_counts["E"][1] * letter_counts["S"][1]
    goes += letter_counts["G"][1] * letter_counts["O"][0] * letter_counts["E"][1] * letter_counts["S"][1]
    goes += letter_counts["G"][1] * letter_counts["O"][1] * letter_counts["E"][0] * letter_counts["S"][1]
    goes += letter_counts["G"][1] * letter_counts["O"][1] * letter_counts["E"][1] * letter_counts["S"][0]
    odd_combinations *= goes
    odd_combinations *= letter_counts["M"][1]
    print(combinations - odd_combinations)


main()
