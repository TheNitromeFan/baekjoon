words = input().split()
new_words = [word for word in words if word not in ["bubble", "tapioka"]]
if not new_words:
    new_words = ["nothing"]
print(" ".join(new_words))
