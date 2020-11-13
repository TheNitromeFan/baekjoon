def order(cards, length):
    students = []
    for i in range(length):
        students.insert(cards[i], i+1)
    return reversed(students)


n = int(input())
draws = [int(x) for x in input().split()]
print(" ".join(str(x) for x in order(draws, n)))
