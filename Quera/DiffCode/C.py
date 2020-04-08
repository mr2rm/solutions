cnt, is_valid = 0, True
for i in range(9):
    s = input()
    if not is_valid:
        continue

    if i not in range(3, 6):
        for j, c in enumerate(s[:3] + s[6:]):
            if i % 6 == 1:
                if j % 3 == 1 and c == '1':
                    is_valid = False
            elif c == '0':
                is_valid = False
        s = s[3:6]

    cnt += s.count('2')

res = 2 ** cnt if is_valid else 0
print(res)
