import sys
import string


def main():
    n, start, finish = (int(x) for x in sys.stdin.readline().split())
    codes = []
    for _ in range(n):
        codes.append(sys.stdin.readline().rstrip())
    permutations = [1] * n
    for i in range(n-1, -1, -1):
        length = len(codes[i])
        for j in range(i):
            permutations[j] *= length
    index = 0
    counter = 0
    while counter < finish:
        code = ""
        x = index
        for i in range(n):
            q, r = divmod(x, permutations[i])
            code += codes[i][q]
            x = r
        index += 1
        if len(set(code)) == len(code):
            counter += 1
            if counter >= start:
                print(code)


main()
