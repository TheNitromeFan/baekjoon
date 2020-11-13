def main():
    n = int(input())
    operands = []
    operators = []
    for _ in range(n - 1):
        operands.append(int(input()))
        operator = input()
        while operator in "+-" and operators and operators[-1] in "*/" or \
                operator in "+-" and operators and operators[-1] in "+-" or \
                operator in "*/" and operators and operators[-1] in "*/":
            op2 = operands.pop()
            op1 = operands.pop()
            op = operators.pop()
            if op == "+":
                operands.append(op1 + op2)
            elif op == "-":
                operands.append(op1 - op2)
            elif op == "*":
                operands.append(op1 * op2)
            elif op == "/":
                operands.append(op1 // op2)
        operators.append(operator)
    operands.append(int(input()))
    while operators:
        op2 = operands.pop()
        op1 = operands.pop()
        op = operators.pop()
        if op == "+":
            operands.append(op1 + op2)
        elif op == "-":
            operands.append(op1 - op2)
        elif op == "*":
            operands.append(op1 * op2)
        elif op == "/":
            operands.append(op1 // op2)
    print(operands[0])


main()
