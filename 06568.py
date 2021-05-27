import sys


pc, accu = 0, 0
memory = []
for _ in range(32):
    memory.append(sys.stdin.readline().rstrip())
while True:
    instr = memory[pc]
    pc += 1
    pc %= 32
    if instr[:3] == "000":
        memory[int(instr[3:], base=2)] = bin(accu)[2:].ljust(8, "0")
    elif instr[:3] == "001":
        accu = int(memory[int(instr[3:], base=2)], base=2)
    elif instr[:3] == "010":
        if accu == 0:
            pc = int(instr[3:], base=2)
    elif instr[:3] == "100":
        accu -= 1
    elif instr[:3] == "101":
        accu += 1
    elif instr[:3] == "110":
        pc = int(instr[3:], base=2)
    elif instr[:3] == "111":
        break
    accu %= 256
print(bin(accu)[2:].ljust(8, "0"))
