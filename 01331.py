FILES = "ABCDEF"
RANKS = "123456"


def valid_move(prev, cur):
    if prev is None:
        return True
    prev_f, prev_r, cur_f, cur_r = prev[0], prev[1], cur[0], cur[1]
    return (abs(FILES.index(prev_f) - FILES.index(cur_f)) == 2 and abs(RANKS.index(prev_r) - RANKS.index(cur_r)) == 1) \
        or (abs(FILES.index(prev_f) - FILES.index(cur_f)) == 1 and abs(RANKS.index(prev_r) - RANKS.index(cur_r)) == 2)


def main():
    visited = {f + r: False for f in FILES for r in RANKS}
    moves = [input() for _ in range(6 ** 2)]
    prev = None
    for cur in moves:
        if cur not in visited or visited[cur] or not valid_move(prev, cur):
            print("Invalid")
            return
        visited[cur] = True
        prev = cur
    cur = moves[0]
    if not valid_move(prev, cur):
        print("Invalid")
        return
    if all(visited.values()):
        print("Valid")
    else:
        print("Invalid")


main()
