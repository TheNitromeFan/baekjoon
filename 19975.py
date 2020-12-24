import sys
import string


def matches(string1, string2):
    if len(string1) != len(string2) or string1[0].lower() != string2[0].lower():
        return False
    for i in range(1, len(string1)):
        if string1[i] != string2[i]:
            return False
    return True


def hyperlink(article, title, redirects):
    new_article = ""
    current_word = ""
    for letter in article:
        if letter not in string.ascii_letters:
            for keyword, target in redirects.items():
                if matches(current_word, keyword):
                    if title == target:
                        continue
                    if keyword == target:
                        new_article += f"[[{current_word}]]"
                    else:
                        new_article += f"[[{target}|{current_word}]]"
                    current_word = ""
                    break
            new_article += current_word
            current_word = ""
            new_article += letter
        else:
            current_word += letter
    for keyword, target in redirects.items():
        if matches(current_word, keyword):
            if title == target:
                continue
            if keyword == target:
                new_article += f"[[{current_word}]]"
            else:
                new_article += f"[[{target}|{current_word}]]"
            break
    else:
        new_article += current_word
    return new_article


def main():
    n = int(sys.stdin.readline())
    titles = []
    articles = {}
    redirects = {}
    for _ in range(n):
        title = sys.stdin.readline().rstrip()
        titles.append(title)
        articles[title] = ""
        m = int(sys.stdin.readline())
        for _ in range(m):
            alternative_title = sys.stdin.readline().rstrip()
            redirects[alternative_title] = title
        redirects[title] = title
        k = int(sys.stdin.readline())
        for _ in range(k):
            articles[title] += sys.stdin.readline()
    for title in titles:
        new_article = hyperlink(articles[title], title, redirects)
        sys.stdout.write(f"{title}\n{new_article}")


main()
