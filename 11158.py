t = int(input())
for _ in range(t):
    words = input().split()
    cnt = 0
    for i, word in enumerate(words):
        if word in ["u", "ur"]:
            cnt += 1
        elif i + 1 < len(words) and word in ["would", "should"] and words[i + 1] == "of":
            cnt += 1
        elif "lol" in word:
            cnt += 1
    print(cnt * 10)
