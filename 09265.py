import sys


def read_int():
    data = sys.stdin.buffer.read(4)
    # print(data)
    if data:
        return int.from_bytes(data, "little")
    else:
        raise EOFError


def main():
    n = read_int()
    m = read_int()
    a = []
    for i in range(n):
        a.append([0] * m)
        for j in range(m):
            a[i][j] = read_int()
    while True:
        try:
            low = read_int()
            high = read_int()
        except EOFError:
            break
        ans = 0
        left, right = len(a[0]) - 1, len(a[0]) - 1
        for i in range(n):
            while left >= 0 and a[i][left] >= low:
                left -= 1
            while right >= 0 and a[i][right] > high:
                right -= 1
            ans += right - left
        sys.stdout.write("{}\n".format(ans))


main()
