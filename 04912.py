import sys
import string


def main():
    while True:
        line = sys.stdin.readline()
        idx = 0
        new_line = ""
        while idx < len(line):
            if idx + 3 <= len(line) and line[idx:idx + 3] == "EOF":
                if new_line:
                    print(new_line)
                return
            elif line[idx] not in string.ascii_lowercase and not line[idx].isspace():
                idx += 1
            elif idx + 2 <= len(line) and line[idx:idx + 2] == "dd":
                new_line += "p"
                idx += 2
            elif idx + 2 <= len(line) and line[idx:idx + 2] == "ei" and not (idx - 1 >= 0 and line[idx - 1] == "c"):
                new_line += "ie"
                idx += 2
            elif idx + 4 <= len(line) and line[idx:idx + 4] == "pink":
                new_line += "floyd"
                idx += 4
            else:
                new_line += line[idx]
                idx += 1
        sys.stdout.write(new_line)


main()
