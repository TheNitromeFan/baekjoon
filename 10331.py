import sys


expression = sys.stdin.readline().rstrip()
answer = int(sys.stdin.readline())
correct = eval(expression)
incorrect = int(expression[0])
for i in range(1, len(expression), 2):
    operator, operand = expression[i], int(expression[i + 1])
    if operator == "+":
        incorrect += operand
    else:
        incorrect *= operand
if answer == correct == incorrect:
    print("U")
elif answer == correct:
    print("M")
elif answer == incorrect:
    print("L")
else:
    print("I")
