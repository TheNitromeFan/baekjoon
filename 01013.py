def main():
    transitions = {('A', '0'): 'B', ('A', '1'): 'C', ('B', '0'): 'dead', ('B', '1'): 'D', ('C', '0'): 'E',
                   ('C', '1'): 'dead', ('D', '0'): 'B', ('D', '1'): 'C', ('E', '0'): 'F', ('E', '1'): 'dead',
                   ('F', '0'): 'F', ('F', '1'): 'G', ('G', '0'): 'B', ('G', '1'): 'H', ('H', '0'): 'I', ('H', '1'): 'H',
                   ('I', '0'): 'F', ('I', '1'): 'D', ('dead', '0'): 'dead', ('dead', '1'): 'dead'}
    final_states = "DGH"
    for _ in range(int(input())):
        current = 'A'
        for c in input():
            current = transitions[(current, c)]
        if current in final_states:
            print("YES")
        else:
            print("NO")


main()
