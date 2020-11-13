MAX = 10 ** 9


def is_number(x):
    try:
        int(x)
        return True
    except:
        return False


def main():
    to_print = []
    while True:
        instructions = []
        while True:
            line = input()
            if line == "QUIT":
                print("\n".join(to_print))
                return
            elif line == "END":
                break
            instructions.append(line)
        for _ in range(int(input())):
            go_stack = [int(input())]
            error_terminated = False
            for instruction in instructions:
                if instruction == "POP":
                    if go_stack:
                        go_stack = go_stack[:-1]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "INV":
                    if go_stack:
                        go_stack[-1] *= -1
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "DUP":
                    if go_stack:
                        go_stack.append(go_stack[-1])
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "SWP":
                    if len(go_stack) >= 2:
                        go_stack[-1], go_stack[-2] = go_stack[-2], go_stack[-1]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "ADD":
                    if len(go_stack) >= 2 and abs(go_stack[-1] + go_stack[-2]) <= MAX:
                        go_stack = go_stack[:-2] + [go_stack[-1] + go_stack[-2]]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "SUB":
                    if len(go_stack) >= 2 and abs(go_stack[-2] - go_stack[-1]) <= MAX:
                        go_stack = go_stack[:-2] + [go_stack[-2] - go_stack[-1]]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "MUL":
                    if len(go_stack) >= 2 and abs(go_stack[-1] * go_stack[-2]) <= MAX:
                        go_stack = go_stack[:-2] + [go_stack[-1] * go_stack[-2]]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "DIV":
                    if len(go_stack) >= 2 and go_stack[-1]:
                        a, b = abs(go_stack[-1]), abs(go_stack[-2])
                        c = b // a
                        if go_stack[-2] * go_stack[-1] < 0:
                            c *= -1
                        go_stack = go_stack[:-2] + [c]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                elif instruction == "MOD":
                    if len(go_stack) >= 2 and go_stack[-1]:
                        a, b = abs(go_stack[-1]), abs(go_stack[-2])
                        c = b % a
                        if go_stack[-2] < 0:
                            c *= -1
                        go_stack = go_stack[:-2] + [c]
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
                else:
                    x = int(instruction[4:])
                    if abs(x) <= MAX:
                        go_stack.append(x)
                    else:
                        to_print.append("ERROR")
                        error_terminated = True
                        break
            if error_terminated:
                continue
            if len(go_stack) == 1:
                to_print.append(str(go_stack[0]))
            else:
                to_print.append("ERROR")
        input()
        to_print.append("")


main()
