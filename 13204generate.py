def find(f, n):
    for m in range(1, 66668):
        i = (2 * m * n + m) // 200000
        if 2 * m * n - m <= 200000 * i < 2 * m * n + m:
            f.write("{}, ".format(m))
            return


def main():
    with open("13204.txt", "w") as f:
        for n in range(1, 100001):
            find(f, n)
            print(n)
            if n % 100 == 0:
                f.write("\n")


main()
