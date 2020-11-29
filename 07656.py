import sys


def main():
    line = sys.stdin.readline().rstrip()
    questions = []
    idx = 0
    question = ""
    while idx < len(line):
        question += line[idx]
        if line[idx] == "?":
            questions.append(question.strip())
            question = ""
        elif line[idx] == ".":
            question = ""
        idx += 1
    for question in questions:
        sys.stdout.write("Forty-two{}.\n".format(question[4:-1]))


main()
