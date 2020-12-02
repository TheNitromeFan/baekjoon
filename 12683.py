import sys
import itertools


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        m, q = (int(x) for x in sys.stdin.readline().split())
        questions = []
        for _ in range(q):
            questions.append(tuple(float(x) for x in sys.stdin.readline().split()))
        products = []
        for comb in itertools.product(range(4), repeat=q):
            product = 1
            for i in range(q):
                product *= questions[i][comb[i] - 1]
            products.append(product)
        sys.stdout.write("Case #{0}: {1:.7f}\n".format(a0, sum(sorted(products, reverse=True)[:m])))


main()
