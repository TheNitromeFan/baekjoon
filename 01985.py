import sys


def almost_friends(x, y):
    for i in range(len(x) - 1):
        nx = x.copy()
        if nx[i] < '9' and nx[i + 1] > '0':
            nx[i], nx[i + 1] = str(int(nx[i]) + 1), str(int(nx[i + 1]) - 1)
            if set(nx) == set(y):
                return True
        nx = x.copy()
        if ((i > 0 and nx[i] > '0') or nx[i] > '1') and nx[i + 1] < '9':
            nx[i], nx[i + 1] = str(int(nx[i]) - 1), str(int(nx[i + 1]) + 1)
            if set(nx) == set(y):
                return True
    for j in range(len(y) - 1):
        ny = y.copy()
        if ny[j] < '9' and ny[j + 1] > '0':
            ny[j], ny[j + 1] = str(int(ny[j]) + 1), str(int(ny[j + 1]) - 1)
            if set(x) == set(ny):
                return True
        ny = y.copy()
        if ((j > 0 and ny[j] > '0') or ny[j] > '1') and ny[j + 1] < '9':
            ny[j], ny[j + 1] = str(int(ny[j]) - 1), str(int(ny[j + 1]) + 1)
            if set(x) == set(ny):
                return True
    return False


def main():
    for _ in range(3):
        x, y = [list(x) for x in sys.stdin.readline().rstrip().split()]
        if set(x) == set(y):
            sys.stdout.write("friends\n")
        elif almost_friends(x, y):
            sys.stdout.write("almost friends\n")
        else:
            sys.stdout.write("nothing\n")


main()
