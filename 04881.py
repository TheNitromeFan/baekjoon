import sys


def sum_of_squared_digits(n):
    ret = 0
    while n:
        ret += (n % 10) ** 2
        n //= 10
    return ret


def main():
    while True:
        a, b = (int(x) for x in sys.stdin.readline().split())
        if a == b == 0:
            break
        prev_a = a
        a_cycle = {prev_a: 1}
        while True:
            next_a = sum_of_squared_digits(prev_a)
            if next_a in a_cycle:
                break
            a_cycle[next_a] = a_cycle[prev_a] + 1
            prev_a = next_a
        prev_b = b
        b_cycle = {prev_b: 1}
        while True:
            next_b = sum_of_squared_digits(prev_b)
            if next_b in b_cycle:
                break
            b_cycle[next_b] = b_cycle[prev_b] + 1
            prev_b = next_b
        intersection = set(a_cycle.keys()) & set(b_cycle.keys())
        if intersection:
            lengths = min(a_cycle[x] + b_cycle[x] for x in intersection)
        else:
            lengths = 0
        sys.stdout.write(f"{a} {b} {lengths}\n")


main()
