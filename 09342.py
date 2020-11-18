import sys


def infected_code(table, code, initial_state, final_state):
    state = initial_state
    for letter in code:
        if (state, letter) in table:
            state = table[(state, letter)]
        else:
            return False
    return final_state in state


def main():
    m = {("01", "A"): "12", ("01", "B"): "1", ("01", "C"): "1", ("01", "D"): "1", ("01", "E"): "1", ("01", "F"): "1",
         ("1", "A"): "12", ("12", "A"): "12", ("12", "F"): "23", ("23", "F"): "23", ("23", "C"): "345",
         ("345", "C"): "345", ("345", "A"): "5", ("345", "B"): "5", ("345", "D"): "5", ("345", "E"): "5",
         ("345", "F"): "5"}
    n = int(sys.stdin.readline())
    for _ in range(n):
        code = sys.stdin.readline().rstrip()
        if infected_code(m, code, "01", "5"):
            print("Infected!")
        else:
            print("Good")


main()
