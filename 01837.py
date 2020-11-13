def is_good(code, prime_max):
    if prime_max == 2:
        return "GOOD",
    elif code % 2 == 0 and prime_max > 2:
        return "BAD", 2
    prime = 3
    while prime < prime_max and prime * prime <= code:
        if code % prime == 0:
            return "BAD", prime
        prime += 2
    return "GOOD",



def main():
    p, k = (int(x) for x in input().split())
    print(" ".join(str(x) for x in is_good(p, k)))


main()
