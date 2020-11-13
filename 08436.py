lisp = "TDLF"
name = input()
print(2 ** sum(name.count(letter) for letter in lisp))
