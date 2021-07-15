import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b, c, d = (int(x) for x in sys.stdin.readline().split())
        category1 = set()
        category2 = {}
        category3 = {}
        for _ in range(a):
            system = sys.stdin.readline().rstrip()
            category1.add(system)
        for _ in range(b):
            system = sys.stdin.readline().rstrip()
            category2[system] = False
        for _ in range(c):
            system = sys.stdin.readline().rstrip()
            category3[system] = 100
        units = 20
        orders = []
        for _ in range(d):
            orders.append(sys.stdin.readline().rstrip())
        for system in orders:
            if system in category1:
                sys.stdout.write(f"recalibrate {system}\n")
            elif system in category2:
                if category2[system]:
                    sys.stdout.write(f"re-invert {system}\n")
                else:
                    sys.stdout.write(f"invert {system}\n")
                category2[system] = not category2[system]
            else:
                category3[system] -= 10
                if units:
                    category3[system] += 10
                    units -= 10
                if category3[system] <= 10:
                    sys.stdout.write("ABANDON SHIP. REPEAT. ALL HANDS ABANDON SHIP.\n")
                    break
                sys.stdout.write(f"divert all power to {system}\n")


main()
