import sys


n = int(sys.stdin.readline())
taro = set()
for _ in range(n):
    taro.add(int(sys.stdin.readline()))
hanako = {x for x in range(1, 2 * n + 1) if x not in taro}
turn = True
deck = 0
while True:
    if turn:
        playable = {x for x in taro if x > deck}
        if playable:
            y = min(playable)
            taro.remove(y)
            if not taro:
                break
            deck = y
        else:
            deck = 0
    else:
        playable = {x for x in hanako if x > deck}
        if playable:
            y = min(playable)2
            hanako.remove(y)
            if not hanako:
                break
            deck = y
        else:
            deck = 0
    turn = not turn
print(len(hanako))
print(len(taro))
