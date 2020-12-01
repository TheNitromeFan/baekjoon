import sys


def main():
    n = int(sys.stdin.readline())
    filetypes = {}
    for _ in range(n):
        file = sys.stdin.readline().rstrip()
        filetype = file[file.index(".") + 1:]
        if filetype in filetypes:
            filetypes[filetype] += 1
        else:
            filetypes[filetype] = 1
    for key, val in sorted(filetypes.items()):
        sys.stdout.write("{} {}\n".format(key, val))


main()
