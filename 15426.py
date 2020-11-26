import sys


def simulate(commands):
    x, y = 0, 0
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    direction = 0
    for command in commands:
        if command == "Forward":
            x += dx[direction]
            y += dy[direction]
        elif command == "Right":
            direction = (direction + 1) % 4
        elif command == "Left":
            direction = (direction - 1) % 4
    return x, y


def main():
    x, y = (int(z) for z in sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    commands = []
    for _ in range(n):
        commands.append(sys.stdin.readline().rstrip())
    for i, command in enumerate(commands):
        new_commands = commands[::]
        for new_command in ["Forward", "Right", "Left"]:
            new_commands[i] = new_command
            if simulate(new_commands) == (x, y):
                sys.stdout.write("{} {}".format(i + 1, new_command))
                return


main()
