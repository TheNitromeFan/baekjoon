import sys
import string


def main():
    entries = sys.stdin.readline().rstrip().split()
    type_name = entries[0]
    letters = string.ascii_letters
    for variable_name in entries[1:]:
        variable_name = variable_name.rstrip(",;")
        i = 0
        while i < len(variable_name) and variable_name[i] in string.ascii_letters:
            i += 1
        variable = variable_name[:i]
        constructors = ""
        while i < len(variable_name):
            if variable_name[i] == "[":
                constructors = "[]" + constructors
                i += 2
            else:
                constructors = variable_name[i] + constructors
                i += 1
        print("{}{} {};".format(type_name, constructors, variable))


main()
