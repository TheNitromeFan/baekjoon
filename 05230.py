import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        entries = sys.stdin.readline().rstrip().split()
        k, string_rep, strings = int(entries[0]), entries[1], entries[2:]
        assignments, binary = {}, {0: ""}
        for i, char in enumerate(string_rep[1:], start=1):
            if i % 2 == 0:
                binary[i] = binary[(i - 1) // 2] + "1"
            else:
                binary[i] = binary[(i - 1) // 2] + "0"
            if char != "*":
                assignments[binary[i]] = char
        for string in strings:
            decoded, cur = "", ""
            for c in string:
                cur += c
                if cur in assignments:
                    decoded += assignments[cur]
                    cur = ""
            print(decoded, end=" ")
        print()


main()
