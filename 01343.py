def main():
    slots = input().split('.')
    ans = []
    for slot in slots:
        if len(slot) % 2:
            print(-1)
            return
        ans.append('AAAA' * (len(slot) // 4) + 'BB' * (len(slot) % 4 // 2))
    print('.'.join(ans))


main()
