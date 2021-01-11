import sys


code = ""
for line in sys.stdin.readlines():
    for c in line.rstrip():
        if c != " " and c != chr(9):
            code += c
indentation = 0
print("{")
indentation += 1
cur = ""
need = True
for c in code[1:]:
    if need and c != "}":
        print(" " * 4 * indentation, end="")
        need = False
    if c == "{":
        print(" {")
        indentation += 1
        need = True
    elif c == "}":
        need = False
        indentation -= 1
        print(" " * 4 * indentation, end="")
        print("}", end="")
    elif c == ";":
        print(";")
        need = True
    elif c == ",":
        print(", ", end="")
    else:
        print(c, end="")
