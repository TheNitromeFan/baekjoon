import string


def evaluate(line):
    operations = "+-*/"
    operators = []
    operands = []
    pos = 0
    while pos < len(line):
        #print(operators, operands)
        if line[pos] in string.digits:
            number = 0
            while pos < len(line) and line[pos] in string.digits:
                number = number * 10 + int(line[pos])
                pos += 1
            operands.append(number)
            continue
        elif line[pos] == '(':
            operators.append(line[pos])
        elif line[pos] in operations:
            while line[pos] in "+-" and operators and operators[-1] in "*/" or\
                line[pos] in "+-" and operators and operators[-1] in "+-" or\
                    line[pos] in "*/" and operators and operators[-1] in "*/":
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
            operators.append(line[pos])
        else:
            while not operators[-1] == '(':
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
            operators.pop()
        pos += 1
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
    if len(operands) != 1:
        raise ValueError
    return operands[0]


def main():
    try:
        print(evaluate(input()))
    except (IndexError, ZeroDivisionError, ValueError):
        print("ROCK")


main()
