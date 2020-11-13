def digits(n):
    ret = []
    while n:
        ret.append(n % 10)
        n //= 10
    return ret


def main():
    y = int(input())
    while True:
        y += 1
        d = digits(y)
        if len(d) == len(set(d)):
            print(y)
            return


main()
