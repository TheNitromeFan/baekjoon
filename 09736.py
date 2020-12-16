import sys


def parse(anbm):
    i, j = anbm.index("a"), anbm.index("b")
    return int(anbm[i + 1:j]), int(anbm[j + 1:])


def multiply(m, n, j, k, p, q):
    r, s = j + p * (-1) ** k, k + q
    return r % m, s % n


def main():
    while True:
        entries = sys.stdin.readline().rstrip().split()
        problem_id = entries[0]
        m, n, p = (int(x) for x in entries[1:])
        if problem_id == "ZZ":
            break
        for _ in range(p):
            elements = sys.stdin.readline().rstrip().split()
            j, k = parse(elements[0])
            p, q = parse(elements[1])
            r, s = multiply(m, n, j, k, p, q)
            sys.stdout.write("ProblemID {}: {} * {} = a{}b{}\n".format(problem_id, elements[0], elements[1], r, s))


main()
