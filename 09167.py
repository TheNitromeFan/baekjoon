import sys
import string
import collections


taunts = collections.deque(["<sentence>", "<taunt> <sentence>", "<noun>!", "<sentence>"])
sentences = collections.deque(
    ["<past-rel> <noun-phrase>", "<present-rel> <noun-phrase>", "<past-rel> <article> <noun>"]
)
modified_nouns = collections.deque(["<noun>", "<modifier> <noun>"])
modifiers = collections.deque(["<adjective>", "<adverb> <adjective>"])
present_persons = collections.deque(["steed", "king", "first-born"])
past_persons = collections.deque(["mother", "father", "grandmother", "grandfather", "godfather"])
nouns = collections.deque(
    ["hamster", "coconut", "duck", "herring", "newt", "peril", "chicken", "vole", "parrot", "mouse", "twit"]
)
present_verbs = collections.deque(["is", "masquerades as"])
past_verbs = collections.deque(["was", "personified"])
adjectives = collections.deque(["silly", "wicked", "sordid", "naughty", "repulsive", "malodorous", "ill-tempered"])
adverbs = collections.deque(["conspicuously", "categorically", "positively", "cruelly", "incontrovertibly"])


def word_count(words):
    ret = 0
    for word in words:
        if any(c in string.ascii_letters for c in word):
            ret += 1
    return ret


def has_the_holy_grail(words):
    line = "".join(words)
    compare = "theholygrail"
    i, j = 0, 0
    while i < len(line):
        if line[i].lower() == compare[j]:
            j += 1
            if j == 12:
                return True
        i += 1
    return False


def get_taunt():
    u = taunts.popleft()
    taunts.append(u)
    if u == "<sentence>":
        taunt = get_sentence()
        return taunt[0].upper() + taunt[1:], False
    elif u == "<taunt> <sentence>":
        x, _ = get_taunt()
        y = get_sentence()
        return x[0].upper() + x[1:] + " " + y[0].upper() + y[1:], True
    else:
        z = get_noun()
        return z[0].upper() + z[1:] + "!", False


def get_sentence():
    u = sentences.popleft()
    sentences.append(u)
    if u == "<past-rel> <noun-phrase>":
        return get_past_rel() + " " + get_noun_phrase()
    elif u == "<present-rel> <noun-phrase>":
        return get_present_rel() + " " + get_noun_phrase()
    else:
        return get_past_rel() + " " + get_article() + " " + get_noun()


def get_noun_phrase():
    return get_article() + " " + get_modified_noun()


def get_modified_noun():
    u = modified_nouns.popleft()
    modified_nouns.append(u)
    if u == "<noun>":
        return get_noun()
    else:
        return get_modifier() + " " + get_noun()


def get_modifier():
    u = modifiers.popleft()
    modifiers.append(u)
    if u == "<adjective>":
        return get_adjective()
    else:
        return get_adverb() + " " + get_adjective()


def get_present_rel():
    return "your " + get_present_person() + " " + get_present_verb()


def get_past_rel():
    return "your " + get_past_person() + " " + get_past_verb()


def get_present_person():
    u = present_persons.popleft()
    present_persons.append(u)
    return u


def get_past_person():
    u = past_persons.popleft()
    past_persons.append(u)
    return u


def get_noun():
    u = nouns.popleft()
    nouns.append(u)
    return u


def get_present_verb():
    u = present_verbs.popleft()
    present_verbs.append(u)
    return u


def get_past_verb():
    u = past_verbs.popleft()
    past_verbs.append(u)
    return u


def get_article():
    return "a"


def get_adjective():
    u = adjectives.popleft()
    adjectives.append(u)
    return u


def get_adverb():
    u = adverbs.popleft()
    adverbs.append(u)
    return u


def main():
    lines = []
    while True:
        try:
            line = sys.stdin.readline().rstrip()
        except EOFError:
            break
        if not line:
            break
        lines.append(line)
    for line in lines:
        words = line.split()
        q, r = divmod(word_count(words), 3)
        taunt_count = q + (r > 0)
        answer = []
        if has_the_holy_grail(words):
            answer.append("(A childish hand gesture)")
            taunt_count -= 1
        while taunt_count > 0:
            taunt, double = get_taunt()
            answer.append(taunt)
            if double:
                taunt_count -= 2
            else:
                taunt_count -= 1
        sys.stdout.write(f"Knight: {' '.join(words)} \n")
        for taunt in answer:
            sys.stdout.write(f"Taunter: {taunt}. \n")
        sys.stdout.write("\n")


main()
