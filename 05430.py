def main():
    t = int(input())
    for _ in range(t):
        commands = input()
        n = int(input())
        L = eval(input())
        reverse = False
        first, last = 0, 0
        for command in commands:
            if command == "R":
                reverse = not reverse
            elif command == "D":
                if reverse:
                    last += 1
                else:
                    first += 1
        if first + last > n:
            print("error")
        elif reverse:
            print("[" + ",".join(str(x) for x in L[::-1][last:n-first]) + "]")
        else:
            print("[" + ",".join(str(x) for x in L[first:n-last]) + "]")


main()
