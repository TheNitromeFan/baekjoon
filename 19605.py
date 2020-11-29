import sys


def main():
    t = sys.stdin.readline().rstrip()
    s = sys.stdin.readline().rstrip()
    shifts = [s[i:] + s[:i] for i, _ in enumerate(s)]
    if any(shift in t for shift in shifts):
        sys.stdout.write("yes")
    else:
        sys.stdout.write("no")


main()
