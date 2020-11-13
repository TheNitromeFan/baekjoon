class Matrix:
    def __init__(self, name, size):
        self.name = name
        self.size = size
        self.elements = {}

    def add(self, other):
        if self.size != other.size:
            raise ValueError
        ret = Matrix(self.name + other.name, self.size)
        for key in self.elements:
            ret.elements[key] = self.elements[key] + other.elements[key]
        return ret

    def multiply(self, other):
        if self.size > other.size:
            raise ValueError
        ret = Matrix(self.name + other.name, other.size - self.size + 1)
        for i in range(1, other.size - self.size + 2):
            for j in range(1, i + 1):
                ret.elements[(i, j)] = 0
                for x in range(1, self.size + 1):
                    for y in range(1, x + 1):
                        ret.elements[(i, j)] \
                            += self.elements[(x, y)] * other.elements[(i - 1 + x, j - 1 + y)]
        return ret


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        matrices = {}
        for _ in range(n):
            line = input().split()
            name, size = line[0], int(line[1])
            matrix = Matrix(name, size)
            for i in range(1, size+1):
                line = input().split()
                for j in range(1, i+1):
                    matrix.elements[(i, j)] = int(line[j-1])
            matrices[name] = matrix
        expression = input().split()
        stack = []
        try:
            for symbol in expression:
                if symbol == '+':
                    second_matrix = stack.pop()
                    first_matrix = stack.pop()
                    stack.append(first_matrix.add(second_matrix))
                elif symbol == '*':
                    second_matrix = stack.pop()
                    first_matrix = stack.pop()
                    stack.append(first_matrix.multiply(second_matrix))
                else:
                    stack.append(matrices[symbol])
            if len(stack) == 1:
                m = stack[0]
                for i in range(1, m.size+1):
                    print(" ".join(str(m.elements[(i, j)]) for j in range(1, i + 1)))
            else:
                raise Exception
        except Exception:
            print("Invalid expression")


main()
