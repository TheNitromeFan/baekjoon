laugh = input()
vowels = "".join(x for x in laugh if x in "aeiou")
if vowels == vowels[::-1]:
    print("S")
else:
    print("N")
