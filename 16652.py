import sys


n, k = (int(x) for x in sys.stdin.readline().split())
emails = set()
for _ in range(k):
    subject = sys.stdin.readline().rstrip()
    if subject in emails:
        continue
    emails.add(subject)
    while len(subject) >= 5 and subject[:4] == "Re: ":
        subject = subject[4:]
        if subject in emails:
            break
        else:
            emails.add(subject)
if n >= len(emails):
    print("YES")
else:
    print("NO")
