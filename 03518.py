import sys


def main():
    lines = []
    for line in sys.stdin.readlines():
        lines.append(line.strip().split())
    m = len(lines)
    n = max(len(line) for line in lines)
    for j in range(n):
        max_length = 0
        for i in range(m):
            if j < len(lines[i]) and max_length < len(lines[i][j]):
                max_length = len(lines[i][j])
        for i in range(m):
            if j < len(lines[i]):
                lines[i][j] = lines[i][j].ljust(max_length)
    for i in range(m):
        sys.stdout.write("{}\n".format(" ".join(lines[i]).strip()))


main()
