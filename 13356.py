import sys
import itertools


def longest_increasing_subsequence(indices, cards, n):
    length = 0
    minima = [None] * (n + 1)
    for i in range(n):
        low, high = 1, length
        while low <= high:
            mid = (low + high + 1) // 2
            if indices[cards[minima[mid]]] < indices[cards[i]]:
                low = mid + 1
            else:
                high = mid - 1
        new_length = low
        minima[new_length] = i
        length = max(length, new_length)
    return length


def main():
    faces = "23456789TJQKA"
    suits = "shdc"
    n = int(sys.stdin.readline())
    cards = sys.stdin.readline().rstrip().split()
    ans = n
    for s in itertools.permutations(suits):
        for directions in itertools.product([1, -1], repeat=4):
            indices = {}
            cnt = 0
            for suit, direction in zip(s, directions):
                if direction == 1:
                    for face in faces:
                        indices[face + suit] = cnt
                        cnt += 1
                else:
                    for face in faces[::-1]:
                        indices[face + suit] = cnt
                        cnt += 1
            ans = min(ans, n - longest_increasing_subsequence(indices, cards, n))
    print(ans)


main()
