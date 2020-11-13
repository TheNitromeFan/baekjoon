def main():
    n = int(input())
    pattern = [int(x) for x in input().split()]
    if len(set(pattern)) < n:
        print("NO")
        return
    pressed = {x: False for x in range(1, 10)}
    for i in range(n-1):
        pressed[pattern[i]] = True
        tmp = {pattern[i], pattern[i+1]}
        if tmp in [{1, 9}, {2, 8}, {3, 7}, {4, 6}] and not pressed[5]:
            print("NO")
            return
        elif tmp == {1, 3} and not pressed[2]:
            print("NO")
            return
        elif tmp == {1, 7} and not pressed[4]:
            print("NO")
            return
        elif tmp == {3, 9} and not pressed[6]:
            print("NO")
            return
        elif tmp == {7, 9} and not pressed[8]:
            print("NO")
            return
    print("YES")


main()
