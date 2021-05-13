import sys


def main():
    mersenne = {11: [23, 89], 23: [47, 178481], 29: [233, 1103, 2089], 37: [223, 616318177], 41: [13367, 164511353],
                43: [431, 9719, 2099863], 47: [2351, 4513, 13264529], 53: [6361, 69431, 20394401],
                59: [179951, 3203431780337]}
    k = int(sys.stdin.readline())
    indices = sorted(x for x in mersenne if x <= k)
    for x in indices:
        print(f"{' * '.join(str(y) for y in mersenne[x])} = {2 ** x - 1} = ( 2 ^ {x} ) - 1")


main()
