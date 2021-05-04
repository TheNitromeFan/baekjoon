import sys


def main():
    line_count = 0
    while True:
        line = sys.stdin.readline().rstrip()
        if line == ".":
            break
        line_count += 1
        left, right = line[:-1].split("=")
        c = int(right)
        if "+" in left:
            a, b = (int(x) for x in left.split("+"))
            hindu = (((a % 9) + (b % 9)) % 9 == c % 9)
        else:
            a, b = (int(x) for x in left.split("*"))
            hindu = (((a % 9) * (b % 9)) % 9 == c % 9)
        if hindu:
            sys.stdout.write(f"{line_count}. PASS\n")
        else:
            sys.stdout.write(f"{line_count}. NOT!\n")


main()
