import sys


def main():
    n = int(sys.stdin.readline())
    logs = []
    cows = set()
    for _ in range(n):
        entries = sys.stdin.readline().split()
        logs.append((int(entries[0]), entries[1], int(entries[2])))
        cows.add(entries[1])
    logs.sort()
    state = {cow: 7 for cow in cows}
    top_cows = {key for key, val in state.items() if val == max(state.values())}
    ans = 0
    for day, cow, delta in logs:
        state[cow] += delta
        new_top_cows = {key for key, val in state.items() if val == max(state.values())}
        if new_top_cows != top_cows:
            ans += 1
        top_cows = new_top_cows
    print(ans)


main()
