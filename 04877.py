import sys


def main():
    lines = sys.stdin.readlines()
    n = len(lines)
    arr = []
    for line in lines:
        entries = [int(x) for x in line.split()]
        arr.append([x / sum(entries) for x in entries])
    probabilities = [1.0] + [0.0] * (n - 1)
    for _ in range(10):
        for probability in probabilities:
            print(f"{probability:.5f}", end=" ")
        print()
        new_probabilities = []
        for j in range(n):
            new_probability = 0.0
            for i, probability in enumerate(probabilities):
                new_probability += probability * arr[i][j]
            new_probabilities.append(new_probability)
        probabilities = new_probabilities[::]


main()
