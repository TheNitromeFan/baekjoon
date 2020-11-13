from string import ascii_uppercase, ascii_lowercase, digits
from random import choice


pool = ascii_lowercase + ascii_uppercase + digits

for _ in range(10000):
    print(choice(pool), end="")
