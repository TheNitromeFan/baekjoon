fibs = [1, 2]


def generate_fibonacci():
    while fibs[-1] < 10 ** 100 :
        fibs.append(fibs[-1] + fibs[-2])


def count_fibs(low, high):
    return len([x for x in fibs if low <= x <= high])


def main():
    generate_fibonacci()
    while True:
        a, b = (int(x) for x in input().split())
        if a == 0 and b == 0:
            break
        print(count_fibs(a, b))


main()
