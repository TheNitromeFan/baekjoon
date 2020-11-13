c = int(input())
for i in range(1, c + 1):
    a = int(input())
    answers = []
    for _ in range(a):
        answers.append(input().replace(" ", ""))
    print("Customer {}".format(i))
    ell = int(input())
    for _ in range(ell):
        n, x, y, ax, ay = input().split()
        if answers[int(n) - 1][int(x) - 1] == ax and answers[int(n) - 1][int(y) - 1] == ay:
            print("correct")
        else:
            print("error")
