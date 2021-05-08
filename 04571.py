import sys


def main():
    problem = 0
    while True:
        a, b = (int(x) for x in sys.stdin.readline().split())
        if a == b == 0:
            break
        problem += 1
        display = [str(a), str(b)]
        indent = 0
        c = b
        while c:
            i = 1
            while c % (10 ** i) == 0:
                i += 1
            prod = a * (c % (10 ** i))
            display.append(str(prod) + " " * indent)
            indent += i
            c //= 10 ** i
        display.append(str(a * b))
        max_length = max(len(s) for s in display)
        print(f"Problem {problem}")
        if len(str(b).rstrip("0")) > 1:
            print(display[0].rjust(max_length).rstrip())
            print(display[1].rjust(max_length).rstrip())
            print("-" * max_length)
            for s in display[2:-1]:
                print(s.rjust(max_length).rstrip())
            print("-" * max_length)
            print(display[-1])
        else:
            print(display[0].rjust(max_length).rstrip())
            print(display[1].rjust(max_length).rstrip())
            print("-" * max_length)
            print(display[-1].rjust(max_length))


main()
