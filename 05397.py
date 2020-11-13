class Node:
    def __init__(self, c, prev, next):
        self.c = c
        self.prev = prev
        self.next = next


def main():
    t = int(input())
    for _ in range(t):
        string = input()
        head = Node('', None, None)
        current = head
        for c in string:
            if c not in '-<>':
                current.next = Node(c, current, current.next)
                current = current.next
                if current.next:
                    current.next.prev = current
            elif c == '<' and current.c:
                current = current.prev
            elif c == '>' and current.next:
                current = current.next
            elif c == '-' and current.c:
                current = current.prev
                current.next = current.next.next
                if current.next:
                    current.next.prev = current
        output = ''
        current = head
        while current:
            output += current.c
            current = current.next
        print(output)


main()
