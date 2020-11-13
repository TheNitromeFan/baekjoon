def main():
    n = int(input())
    for _ in range(n):
        problem = input()
        if problem == "P=NP":
            print("skipped")
            continue
        print(sum(int(x) for x in problem.split('+')))


main()
