import math

def main():
    e = 0
    print("n e\n- -----------")
    for n in range(10):
        e += 1/math.factorial(n)
        if n < 2:
            print("{0} {1}".format(n, int(e)))
        elif n == 2:
            print("{0} {1:.1f}".format(n, e))
        else:
            print("{0} {1:.9f}".format(n, e))


main()
