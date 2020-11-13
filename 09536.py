def main():
    t = int(input())
    for _ in range(t):
        sounds = input().split()
        other = []
        while True:
            line = input()
            if line == "what does the fox say?":
                break
            words = line.split()
            other.append(words[-1])
        print(" ".join(sound for sound in sounds if sound not in other))


main()
