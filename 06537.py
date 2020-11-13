while True:
    line = input()
    n = int(line[:2]) * 10 ** int(line[3])
    if n == 0:
        break
    b = bin(n)[2:]
    print(int(b[1:] + b[0], base=2))
