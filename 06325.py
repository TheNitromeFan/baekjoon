import string


def main():
    case = 0
    while True:
        n = int(input())
        if n == 0:
            break
        case += 1
        assigned = {letter: False for letter in string.ascii_lowercase}
        assigned["a"] = True
        for _ in range(n):
            v1, v2 = input().split(" = ")
            assigned[v1] = assigned[v2]
        defined = [x for x in string.ascii_lowercase if assigned[x]]
        print("Program #{}".format(case))
        if defined:
            print(" ".join(defined) + "\n")
        else:
            print("none\n")


main()
