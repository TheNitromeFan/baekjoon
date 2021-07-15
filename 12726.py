import sys


def find_customer_with_all_malted(prefs):
    for i, pref in enumerate(prefs):
        if all(pref.values()):
            return i
    return -1


def solve(prefs, n):
    malts = {x: 0 for x in range(1, n + 1)}
    while True:
        customer = find_customer_with_all_malted(prefs)
        if customer == -1:
            break
        shake = list(prefs[customer].keys())[0]
        malts[shake] = 1
        new_prefs = []
        for pref in prefs:
            if shake in pref and pref[shake] == 1:
                continue
            elif shake in pref:
                del pref[shake]
                if not pref:
                    return False
            new_prefs.append(pref)
        prefs = new_prefs
    return malts


def main():
    c = int(sys.stdin.readline())
    for a0 in range(1, c + 1):
        n = int(sys.stdin.readline())
        m = int(sys.stdin.readline())
        prefs = []
        for _ in range(m):
            pairs = [int(x) for x in sys.stdin.readline().split()]
            pref = {}
            for idx in range(1, len(pairs), 2):
                flavor, malted = pairs[idx], pairs[idx + 1]
                pref[flavor] = malted
            prefs.append(pref)
        ans = solve(prefs, n)
        sys.stdout.write(f"Case #{a0}:")
        if ans:
            for x in range(1, n + 1):
                sys.stdout.write(f" {ans[x]}")
        else:
            sys.stdout.write(" IMPOSSIBLE")
        sys.stdout.write("\n")


main()
