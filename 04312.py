while True:
    n = int(input())
    if n == 0:
        break
    elif n == 1:
        print("{ }")
        continue
    n -= 1
    to_print = []
    i = 0
    while n:
        if n % 2:
            to_print.append(3 ** i)
        n //= 2
        i += 1
    print("{ " + ", ".join(str(x) for x in to_print) + " }")
