t = int(input())
for i in range(1, t + 1):
    n = int(input())
    robots = [input() for _ in range(n)]
    found = {robot: False for robot in robots}
    d = int(input())
    for _ in range(d):
        line = input()
        for word in line.split():
            if word in found:
                found[word] = True
    print("Test set {}:".format(i))
    for robot in robots:
        if found[robot]:
            print("{} is present".format(robot))
        else:
            print("{} is absent".format(robot))
    print()
