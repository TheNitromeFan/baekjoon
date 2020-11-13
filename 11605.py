def execute(m, commands):
    for command, x in commands:
        if command == "ADD":
            m += x
        elif command == "SUBTRACT":
            m -= x
            if m < 0:
                return False
        elif command == "MULTIPLY":
            m *= x
        elif command == "DIVIDE":
            if m % x != 0:
                return False
            m //= x
    return True


def main():
    n = int(input())
    commands = []
    for _ in range(n):
        args = input().split()
        command, k = args[0], int(args[1])
        commands.append((command, k))
    cnt = 0
    for m in range(1, 101):
        if not execute(m, commands):
            cnt += 1
    print(cnt)


main()
