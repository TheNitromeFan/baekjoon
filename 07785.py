def main():
    n = int(input())
    workers = set()
    for _ in range(n):
        name, action = input().split()
        if action == "enter":
            workers.add(name)
        else:
            workers.remove(name)
    print("\n".join(sorted(workers, reverse=True)))


main()
