def main():
    t = int(input())
    for _ in range(t):
        input()
        input()
        list1 = input().split()
        list2 = input().split()
        counts1 = {x: list1.count(x) for x in list1}
        counts2 = {x: list2.count(x) for x in list2}
        if sorted(counts1.values()) == sorted(counts2.values()):
            print("what a lovely party")
        else:
            print("you've messed up, Cornell")


main()
