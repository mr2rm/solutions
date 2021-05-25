s, p = input(), input()

found = False
for i in range(len(s)):
    j, match = i, True
    for c in p:
        if c != s[j]:
            match = False
            break
        j = (j + 1) % len(s)
    if match:
        found = True
        break
print('Yes' if found else 'No')
