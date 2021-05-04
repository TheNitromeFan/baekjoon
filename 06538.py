import sys


def main():
    for line in sys.stdin.readlines():
        line = line[:-1]
        idx = 0
        while idx < len(line):
            non_repeating = ""
            while idx + 1 < len(line) and line[idx] != line[idx + 1]:
                non_repeating += line[idx]
                idx += 1
            if idx + 1 == len(line):
                non_repeating += line[idx]
                idx += 1
            if non_repeating:
                sys.stdout.write("1")
                for letter in non_repeating:
                    if letter == "1":
                        sys.stdout.write("11")
                    else:
                        sys.stdout.write(letter)
                sys.stdout.write("1")
            if idx == len(line):
                break
            start = idx
            cnt = 0
            end = start
            while end < len(line) and line[end] == line[start] and cnt < 9:
                end += 1
                cnt += 1
            sys.stdout.write(f"{cnt}{line[idx]}")
            idx = end
        sys.stdout.write("\n")


main()
