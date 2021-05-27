def test(n):
    for l in range(1, 1000000):
        prod = 1
        a = list(range(l, l + n))
        for i in a:
            prod *= i
        for c in range(2 ** n):
            b = a[::]
            for i in range(n):
                if c % 2:
                    b[i] += 1
                else:
                    b[i] -= 1
                c //= 2
            new_prod = 1
            for j in b:
                new_prod *= j
            if prod == new_prod:
                print(a, b)
                return
    print("NO")


for n in range(1, 10):
    test(n)
