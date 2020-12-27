import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        entries = [int(x) for x in sys.stdin.readline().split()]
        n, sequence = entries[0], entries[1:]
        d = sequence[1] - sequence[0]
        if all(sequence[i + 1] - sequence[i] == d for i in range(1, n - 1)):
            sys.stdout.write(f"The next 5 numbers after {sequence} are: ")
            for _ in range(5):
                sequence.append(sequence[-1] + d)
            sys.stdout.write(f"{sequence[-5:]}\n")
        else:
            sys.stdout.write(f"The sequence {sequence} is not an arithmetic sequence.\n")


main()
