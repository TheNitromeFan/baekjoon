word = input()
if all(letter in "IOSHZXN" for letter in word):
    print("YES")
else:
    print("NO")
